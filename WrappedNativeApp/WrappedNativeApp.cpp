#include "WrappedNativeApp.h"
#include "StartObject.h"

namespace WrappedNativeApp
{
#pragma region code executed in uiThread
	WrappedNativeApplication::WrappedNativeApplication()
	{
		// Uncomment the line below (or paste in another method), and add watch to "currThread" to find out identity of the current thread in debugger
		//Thread^ currThread = Thread::CurrentThread;

		renderingTimer = gcnew System::Timers::Timer();
		renderingTimer->Interval = 33;
		renderingTimer->Elapsed += gcnew System::Timers::ElapsedEventHandler(this, &WrappedNativeApplication::renderingTimer_Elapsed);
		increaseRotation = decreaseRotation = false;
		increaseOffset = decreaseOffset = false;
	}

	void WrappedNativeApplication::SetThreadManager(IThreadManager^ paramThreadManager)
	{
		threadManager = paramThreadManager;
		StartAppThread();
	}

	void WrappedNativeApplication::StartAppThread()
	{
		List<Object^>^ threadList = gcnew List<Object^>();
		threadList->Add(gcnew KeyValuePair<String^, Delegate^>(AppThreadActionStrings::nativeApplicationStartString,	gcnew VoidObjectDelegate(this, &WrappedNativeApplication::ExecuteInitialize)));
		threadList->Add(gcnew KeyValuePair<String^, Delegate^>(AppThreadActionStrings::startGLThreadString,				gcnew VoidIntPtrVoidIntIntDelegate(this, &WrappedNativeApplication::ExecuteStartGLThread)));
		threadList->Add(gcnew KeyValuePair<String^, Delegate^>(AppThreadActionStrings::nativeApplicationDestroyString,	gcnew VoidVoidDelegate(this, &WrappedNativeApplication::~WrappedNativeApplication)));
		threadList->Add(gcnew KeyValuePair<String^, Delegate^>(AppThreadActionStrings::startRenderingTimerString,		gcnew VoidVoidDelegate(this, &WrappedNativeApplication::ExecuteStartRenderingTimer)));
		threadList->Add(gcnew KeyValuePair<String^, Delegate^>(AppThreadActionStrings::keyDownString,					gcnew VoidObjectDelegate(this, &WrappedNativeApplication::ExecuteKeyDown)));
		threadList->Add(gcnew KeyValuePair<String^, Delegate^>(AppThreadActionStrings::keyPressString,					gcnew VoidObjectDelegate(this, &WrappedNativeApplication::ExecuteKeyPress)));
		threadList->Add(gcnew KeyValuePair<String^, Delegate^>(AppThreadActionStrings::keyUpString, 					gcnew VoidObjectDelegate(this, &WrappedNativeApplication::ExecuteKeyUp)));
		threadList->Add(gcnew KeyValuePair<String^, Delegate^>(AppThreadActionStrings::mouseClickString, 				gcnew VoidObjectDelegate(this, &WrappedNativeApplication::ExecuteMouseClick)));
		threadList->Add(gcnew KeyValuePair<String^, Delegate^>(AppThreadActionStrings::mouseDoubleClickString,			gcnew VoidObjectDelegate(this, &WrappedNativeApplication::ExecuteMouseDoubleClick)));
		threadList->Add(gcnew KeyValuePair<String^, Delegate^>(AppThreadActionStrings::mouseDownString, 				gcnew VoidObjectDelegate(this, &WrappedNativeApplication::ExecuteMouseDown)));
		threadList->Add(gcnew KeyValuePair<String^, Delegate^>(AppThreadActionStrings::mouseEnterString, 				gcnew VoidObjectDelegate(this, &WrappedNativeApplication::ExecuteMouseEnter)));
		threadList->Add(gcnew KeyValuePair<String^, Delegate^>(AppThreadActionStrings::mouseHoverString, 				gcnew VoidObjectDelegate(this, &WrappedNativeApplication::ExecuteMouseHover)));
		threadList->Add(gcnew KeyValuePair<String^, Delegate^>(AppThreadActionStrings::mouseLeaveString, 				gcnew VoidObjectDelegate(this, &WrappedNativeApplication::ExecuteMouseLeave)));
		threadList->Add(gcnew KeyValuePair<String^, Delegate^>(AppThreadActionStrings::mouseMoveString, 				gcnew VoidObjectDelegate(this, &WrappedNativeApplication::ExecuteMouseMove)));
		threadList->Add(gcnew KeyValuePair<String^, Delegate^>(AppThreadActionStrings::mouseUpString, 					gcnew VoidObjectDelegate(this, &WrappedNativeApplication::ExecuteMouseUp)));
		threadList->Add(gcnew KeyValuePair<String^, Delegate^>(AppThreadActionStrings::mouseWheelString, 				gcnew VoidObjectDelegate(this, &WrappedNativeApplication::ExecuteMouseWheel)));
		threadManager->StartAppThread(threadList);
	}
#pragma endregion

#pragma region code executed in appThread
	void WrappedNativeApplication::ExecuteStartGLThread(IntPtr handle, int width, int height)
	{
		Debug::Assert(Thread::CurrentThread->ManagedThreadId == threadManager->GetAppThreadId());
		List<Object^>^ threadList = gcnew List<Object^>();
		threadList->Add(handle);
		threadList->Add(width);
		threadList->Add(height);
		threadList->Add(gcnew KeyValuePair<String^, Delegate^>(GLThreadActionStrings::glInitString, gcnew VoidIntPtr3Delegate(this, &WrappedNativeApplication::ExecuteOpenGLInit)));
		threadList->Add(gcnew KeyValuePair<String^, Delegate^>(GLThreadActionStrings::glDeinitString, gcnew VoidVoidDelegate(this, &WrappedNativeApplication::ExecuteOpenGLDeinit)));
		threadList->Add(gcnew KeyValuePair<String^, Delegate^>(GLThreadActionStrings::glResizeString, gcnew VoidIntIntDelegate(this, &WrappedNativeApplication::ExecuteResize)));
		threadList->Add(gcnew KeyValuePair<String^, Delegate^>(GLThreadActionStrings::glRenderString, gcnew VoidVoidDelegate(this, &WrappedNativeApplication::ExecuteRender)));
		threadManager->StartGLThread(threadList);
	}

	WrappedNativeApplication::~WrappedNativeApplication()
	{
		renderingTimer->Stop();
		renderingTimer->Elapsed -= gcnew System::Timers::ElapsedEventHandler(this, &WrappedNativeApplication::renderingTimer_Elapsed);
		this->!WrappedNativeApplication();
	}

	WrappedNativeApplication::!WrappedNativeApplication()
	{
		delete nativeApplication;
		nativeApplication = 0;
	}

	void WrappedNativeApplication::ExecuteInitialize(Object^ startArg)
	{
		Debug::Assert(Thread::CurrentThread->ManagedThreadId == threadManager->GetAppThreadId());
		nativeApplication = new NativeApplication();
		StartObject^ startObject = (StartObject^)startArg;
		try { nativeApplication->Initialize(startObject->verticalOffset, startObject->rotationSpeed); }
		catch (const NativeException& e) { throw gcnew WrappedNativeException(e); }
	}

	void WrappedNativeApplication::ExecuteStartRenderingTimer()
	{
		Debug::Assert(Thread::CurrentThread->ManagedThreadId == threadManager->GetAppThreadId());
		renderingTimer->Start();
	}

	void WrappedNativeApplication::ExecuteKeyDown(Object^ arg)
	{
		Debug::Assert(Thread::CurrentThread->ManagedThreadId == threadManager->GetAppThreadId());
		
		// need to cast arg to appropriate EventArgs child class first
		KeyEventArgs^ e = (KeyEventArgs^)arg;
		switch (e->KeyCode)
		{
		case Keys::W:
		case Keys::Up:
			increaseOffset = true;
			break;
		case Keys::S:
		case Keys::Down:
			decreaseOffset = true;
			break;
		case Keys::Right:
		case Keys::D:
			increaseRotation = true;
			break;
		case Keys::Left:
		case Keys::A:
			decreaseRotation = true;
			break;
		}
	}

	void WrappedNativeApplication::ExecuteKeyUp(Object^ arg)
	{
		Debug::Assert(Thread::CurrentThread->ManagedThreadId == threadManager->GetAppThreadId());

		KeyEventArgs^ e = (KeyEventArgs^)arg;
		switch (e->KeyCode)
		{
		case Keys::W:
		case Keys::Up:
		case Keys::S:
		case Keys::Down:
			increaseOffset = decreaseOffset = false;
			break;
		case Keys::D:
		case Keys::A:
		case Keys::Right:
		case Keys::Left:
			increaseRotation = decreaseRotation = false;
			break;
		case Keys::Q:
			threadManager->EnqueueCustomAction1(42);
			break;
		case Keys::F:
			threadManager->EnqueueFullScreen();
			break;
		}
	}
#pragma endregion

#pragma region code executed in glThread
	void WrappedNativeApplication::ExecuteOpenGLInit(IntPtr windowHandle, IntPtr deviceContext, IntPtr renderingContext)
	{
		Debug::Assert(Thread::CurrentThread->ManagedThreadId == threadManager->GetGLThreadId());
		try { nativeApplication->OpenGLInit((HWND)windowHandle.ToPointer(), (HDC)deviceContext.ToPointer(), (HGLRC)renderingContext.ToPointer()); }
		catch (const NativeException& e) { throw gcnew WrappedNativeException(e); }
	}

	void WrappedNativeApplication::ExecuteOpenGLDeinit()
	{
		Debug::Assert(Thread::CurrentThread->ManagedThreadId == threadManager->GetGLThreadId());
		nativeApplication->DeinitGraphics();
	}

	void  WrappedNativeApplication::ExecuteResize(int width, int height)
	{
		Debug::Assert(Thread::CurrentThread->ManagedThreadId == threadManager->GetGLThreadId());
		nativeApplication->Resize(width, height);
	}

	void WrappedNativeApplication::ExecuteRender()
	{
		Debug::Assert(Thread::CurrentThread->ManagedThreadId == threadManager->GetGLThreadId());
		nativeApplication->Render();
		threadManager->SwapOpenGLBuffers();
	}
#pragma endregion

#pragma region code executed in ThreadPool thread (that renderingTimer internally uses)
	// Since this code is executing in ThreadPool thread, I might want to enqueue native application's action.
	// This is not necessary if that application's action isn't being called from multiple threads and doesn't invoke actions meant to execute on a different thread
	void WrappedNativeApplication::renderingTimer_Elapsed(Object^ sender, System::Timers::ElapsedEventArgs^ e)
	{
		// if something was requested via UI, see to that first
		if (increaseOffset)
			nativeApplication->IncreaseOffset();
		if (decreaseOffset)
			nativeApplication->DecreaseOffset();

		if (increaseRotation)
			nativeApplication->IncreaseRotation();
		if (decreaseRotation)
			nativeApplication->DecreaseRotation();

		// ... then render scene
		threadManager->EnqueueOpenGLRender();
	}
#pragma endregion
}
