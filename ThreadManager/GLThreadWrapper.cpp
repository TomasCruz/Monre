#include "GLThreadWrapper.h"
#include "NativeExceptionBase.h"

#using <System.Windows.Forms.dll>

using namespace System::Windows::Forms;

namespace ThreadManager
{
	GLThreadWrapper::GLThreadWrapper(IAppThreadWrapper^ appThread) : ThreadWrapperBase()
	{
		appThreadWrapper = appThread;
	}

	GLThreadWrapper::~GLThreadWrapper()
	{
	}

	void GLThreadWrapper::InitThread()
	{
		hDC = GetDC((HWND)formHandle.ToPointer());
		if (hDC == NULL)
			throw gcnew Exception("GetDC failed!");

		if (!MySetPixelFormat())
			throw gcnew Exception("MySetPixelFormat failed!");
	}

	void GLThreadWrapper::DeinitThread()
	{
		try { delegateDictionary[GLThreadActionStrings::glDeinitString]->DynamicInvoke(); }
		catch(Exception^) {} // ignore those
	}

	void GLThreadWrapper::EnqueueOpenGLInit(IntPtr windowHandle, IntPtr deviceContext, IntPtr renderingContext)
	{ EnqueueDictionaryAction(GLThreadActionStrings::glInitString, windowHandle, deviceContext, renderingContext); }
	void GLThreadWrapper::EnqueueOpenGLResize(int width, int height)	{ EnqueueDictionaryAction(GLThreadActionStrings::glResizeString, width, height); }
	void GLThreadWrapper::EnqueueOpenGLRender()							{ EnqueueDictionaryAction(GLThreadActionStrings::glRenderString); }
	void GLThreadWrapper::SwapOpenGLBuffers()							{ ::SwapBuffers(hDC); }

	void GLThreadWrapper::CreateThread()
	{
		thread = gcnew Thread(gcnew ParameterizedThreadStart(this, &GLThreadWrapper::ExecuteThread));
		thread->Priority = ThreadPriority::AboveNormal;
		thread->Name = "glThread";
	}

	void GLThreadWrapper::ProcessThreadList(List<Object^>^ threadList)
	{
		formHandle = (IntPtr)threadList[0];

		KeyValuePair<String^, Delegate^>^ currKVPair;
		for (int i = 3; i < threadList->Count; i++)
		{
			currKVPair = (KeyValuePair<String^, Delegate^>^)threadList[i];
			delegateDictionary->Add(currKVPair->Key, currKVPair->Value);
		}
		EnqueueOpenGLResize((int)threadList[1], (int)threadList[2]);
	}

	void GLThreadWrapper::ExecuteThread(Object^ startArg)
	{
		ProcessThreadList((List<Object^>^)startArg);
		try { InitThread(); }
		catch (Exception^ exc)
		{
			System::Windows::Forms::MessageBox::Show(exc->ToString());
			System::Environment::Exit(1);
		}

		// OpenGL init needs to be executed before execution of rendering. Rendering might have been scheduled by now, but not yet executed
		try { delegateDictionary[GLThreadActionStrings::glInitString]->DynamicInvoke(formHandle, (IntPtr)hDC, (IntPtr)hGLRC); }
		catch(System::Reflection::TargetInvocationException^ tie)
		{
			NativeExceptionBase^ inner = (NativeExceptionBase^)tie->InnerException;
			System::Windows::Forms::MessageBox::Show(inner->ToString());
			System::Environment::Exit(1);
		}
		catch(System::Reflection::TargetParameterCountException^ tpce) { System::Windows::Forms::MessageBox::Show(tpce->ToString()); }
		catch(NativeExceptionBase^ e) { System::Windows::Forms::MessageBox::Show(e->ToString()); }

		appThreadWrapper->EnqueueStartRenderingTimer();

		// do until the termination was not requested
		while (!terminated->WaitOne(0))
		{
			// renderingTimer will enqueue rendering periodically
			DoActions();

			// wait for the new events
			waitLock->WaitOne();
		}

		DeinitThread();
	}

#pragma region Create dummy OpenGL context
	int GLThreadWrapper::FindPixelFormat(int colorBits, int depthBits, int stencilBits)
	{
		int currMode;                               // pixel format mode ID
		int bestMode = 0;                           // return value, best pixel format
		int currScore = 0;                          // points of current mode
		int bestScore = 0;                          // points of best candidate
		PIXELFORMATDESCRIPTOR pfd;

		// search the available formats for the best mode
		for(currMode = 1; ::DescribePixelFormat(hDC, currMode, sizeof(pfd), &pfd) > 0; ++currMode)
		{
			// ignore if cannot support opengl
			if(!(pfd.dwFlags & PFD_SUPPORT_OPENGL))
				continue;

			// ignore if cannot render into a window
			if(!(pfd.dwFlags & PFD_DRAW_TO_WINDOW))
				continue;

			// ignore if cannot support rgba mode
			if((pfd.iPixelType != PFD_TYPE_RGBA) || (pfd.dwFlags & PFD_NEED_PALETTE))
				continue;

			// ignore if not double buffer
			if(!(pfd.dwFlags & PFD_DOUBLEBUFFER))
				continue;

			// try to find best candidate
			currScore = 0;

			// colour bits
			if(pfd.cColorBits >= colorBits) ++currScore;
			if(pfd.cColorBits == colorBits) ++currScore;

			// depth bits
			if(pfd.cDepthBits >= depthBits) ++currScore;
			if(pfd.cDepthBits == depthBits) ++currScore;

			// stencil bits
			if(pfd.cStencilBits >= stencilBits) ++currScore;
			if(pfd.cStencilBits == stencilBits) ++currScore;

			// alpha bits
			if(pfd.cAlphaBits > 0) ++currScore;

			// check if it is best mode so far
			if(currScore > bestScore)
			{
				bestScore = currScore;
				bestMode = currMode;
			}
		}

		return bestMode;
	}

	int GLThreadWrapper::MySetPixelFormat()
	{
		PIXELFORMATDESCRIPTOR pfd;			
		int  iPixelFormat; 
		int colorBits = 32, depthBits = 24, stencilBits = 8;

		// get the device context's best, available pixel format match 
		if ((iPixelFormat = FindPixelFormat(colorBits, depthBits, stencilBits)) == 0)
		{
			MessageBox::Show("ChoosePixelFormat Failed");
			return 0;
		}
		
		::DescribePixelFormat(hDC, iPixelFormat, sizeof(pfd), &pfd);

		// make that match the device context's current pixel format 
		if (::SetPixelFormat(hDC, iPixelFormat, &pfd) == FALSE)
		{
			MessageBox::Show("SetPixelFormat Failed");
			return 0;
		}

		if ((hGLRC = ::wglCreateContext(hDC)) == NULL)
		{
			MessageBox::Show("wglCreateContext Failed");
			return 0;
		}

		if ((::wglMakeCurrent(hDC, hGLRC)) == FALSE)
		{
			MessageBox::Show("wglMakeCurrent Failed");
			return 0;
		}

		return 1;
	}
#pragma endregion
}
