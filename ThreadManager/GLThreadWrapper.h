#ifndef _GLThreadWrapper_h_
#define _GLThreadWrapper_h_

#include <windows.h>
#include "IGLThreadWrapper.h"
#include "ThreadWrapperBase.h"
#include "DelegateTypes.h"
#include "GLThreadActionStrings.h"
#include "IAppThreadWrapper.h"

namespace ThreadManager
{
	public ref class GLThreadWrapper : public ThreadWrapperBase, public IGLThreadWrapper
	{
	public:
		GLThreadWrapper(IAppThreadWrapper^ appThread);
		~GLThreadWrapper();

		virtual void EnqueueOpenGLInit(IntPtr windowHandle, IntPtr deviceContext, IntPtr renderingContext);
		virtual void EnqueueOpenGLResize(int width, int height);
		virtual void EnqueueOpenGLRender();
		virtual void CreateThread() override;
		virtual void SwapOpenGLBuffers();

	protected:
		virtual void ProcessThreadList(List<Object^>^ threadList) override;
		virtual void ExecuteThread(Object^ startArg) override;
		virtual void InitThread() override;
		virtual void DeinitThread() override;

	private:
		HDC hDC;
		HGLRC hGLRC;
		IntPtr formHandle;
		IAppThreadWrapper^ appThreadWrapper;

		int FindPixelFormat(int colorBits, int depthBits, int stencilBits);
		int MySetPixelFormat();
	};
}
#endif
