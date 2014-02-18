#ifndef _ThreadManager_h_
#define _ThreadManager_h_

#include "IThreadManager.h"
#include "IGLThreadWrapper.h"
#include "IAppThreadWrapper.h"
#include "ICallbackThreadWrapper.h"

namespace ThreadManager
{
	public ref class ThreadManager : public IThreadManager
	{
	public:
		ThreadManager(IGLThreadWrapper^ glThreadWrapper, IAppThreadWrapper^ appThreadWrapper, ICallbackThreadWrapper^ callbackThreadWrapper);
		~ThreadManager();
		virtual void TerminateThreads();

		// gl thread
		virtual void StartGLThread(Object^ startArg);
		virtual int GetGLThreadId();

		virtual void EnqueueOpenGLInit(IntPtr windowHandle, IntPtr deviceContext, IntPtr renderingContext);
		virtual void EnqueueOpenGLResize(int width, int height);
		virtual void EnqueueOpenGLRender();
		virtual void SwapOpenGLBuffers();

		// app thread
		virtual void StartAppThread(Object^ startArg);
		virtual int GetAppThreadId();

		virtual void EnqueueStartGLThread(IntPtr handle, int width, int height);
		virtual void EnqueueStartRenderingTimer();
		virtual void EnqueueKeyDown(Object^ e);
		virtual void EnqueueKeyPress(Object^ e);
		virtual void EnqueueKeyUp(Object^ e);
		virtual void EnqueueMouseClick(Object^ e);
		virtual void EnqueueMouseDoubleClick(Object^ e);
		virtual void EnqueueMouseDown(Object^ e);
		virtual void EnqueueMouseEnter(Object^ e);
		virtual void EnqueueMouseHover(Object^ e);
		virtual void EnqueueMouseLeave(Object^ e);
		virtual void EnqueueMouseMove(Object^ e);
		virtual void EnqueueMouseUp(Object^ e);
		virtual void EnqueueMouseWheel(Object^ e);

		// callback thread
		virtual void StartCallbackThread(Object^ startArg);
		virtual int GetCallbackThreadId();

		virtual void EnqueueFullScreen();
		virtual void EnqueueCustomAction1(Object^ arg);
		virtual void EnqueueCustomAction2(Object^ arg);
		virtual void EnqueueCustomAction3(Object^ arg);
		virtual void EnqueueCustomAction4(Object^ arg);
		virtual void EnqueueCustomAction5(Object^ arg);
		virtual void EnqueueCustomAction6(Object^ arg);
		virtual void EnqueueCustomAction7(Object^ arg);
		virtual void EnqueueCustomAction8(Object^ arg);

	protected:
		void TerminateGLThread();
		void TerminateAppThread();
		void TerminateCallbackThread();

	private:
		IGLThreadWrapper^ glThread;
		IAppThreadWrapper^ appThread;
		ICallbackThreadWrapper^ callbackThread;
	};
}
#endif
