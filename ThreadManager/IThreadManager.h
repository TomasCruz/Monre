#ifndef _IThreadManager_h_
#define _IThreadManager_h_

using namespace System;
using namespace System::Threading;
using namespace System::Collections::Generic;

namespace ThreadManager
{
	public interface class IThreadManager
	{
		void TerminateThreads();

		// GL thread
		void StartGLThread(Object^ startArg);
		int GetGLThreadId();

		void EnqueueOpenGLInit(IntPtr windowHandle, IntPtr deviceContext, IntPtr renderingContext);
		void EnqueueOpenGLResize(int width, int height);
		void EnqueueOpenGLRender();
		void SwapOpenGLBuffers();

		// App thread
		void StartAppThread(Object^ startArg);
		int GetAppThreadId();

		void EnqueueStartGLThread(IntPtr handle, int width, int height);
		void EnqueueStartRenderingTimer();
		void EnqueueKeyDown(Object^ e);
		void EnqueueKeyPress(Object^ e);
		void EnqueueKeyUp(Object^ e);
		void EnqueueMouseClick(Object^ e);
		void EnqueueMouseDoubleClick(Object^ e);
		void EnqueueMouseDown(Object^ e);
		void EnqueueMouseEnter(Object^ e);
		void EnqueueMouseHover(Object^ e);
		void EnqueueMouseLeave(Object^ e);
		void EnqueueMouseMove(Object^ e);
		void EnqueueMouseUp(Object^ e);
		void EnqueueMouseWheel(Object^ e);

		// callback thread
		void StartCallbackThread(Object^ startArg);
		int GetCallbackThreadId();

		void EnqueueFullScreen();
		void EnqueueCustomAction1(Object^ arg);
		void EnqueueCustomAction2(Object^ arg);
		void EnqueueCustomAction3(Object^ arg);
		void EnqueueCustomAction4(Object^ arg);
		void EnqueueCustomAction5(Object^ arg);
		void EnqueueCustomAction6(Object^ arg);
		void EnqueueCustomAction7(Object^ arg);
		void EnqueueCustomAction8(Object^ arg);
	};
}
#endif
