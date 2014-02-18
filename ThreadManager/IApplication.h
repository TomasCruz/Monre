#ifndef __IApplication_h__
#define __IApplication_h__

using namespace System;

namespace ThreadManager
{
	public interface class IApplication
	{
		// GL thread
		void ExecuteInitialize(Object^ startArg);
		void ExecuteOpenGLInit(IntPtr windowHandle, IntPtr deviceContext, IntPtr renderingContext);
		void ExecuteOpenGLDeinit();
		void ExecuteRender();
		void ExecuteResize(int width, int height);

		// App thread
		void StartAppThread();
		void ExecuteStartGLThread(IntPtr handle, int width, int height);
		void ExecuteKeyDown(Object^ arg);
		void ExecuteKeyPress(Object^ arg);
		void ExecuteKeyUp(Object^ arg);
		void ExecuteMouseClick(Object^ arg);
		void ExecuteMouseDoubleClick(Object^ arg);
		void ExecuteMouseDown(Object^ arg);
		void ExecuteMouseEnter(Object^ arg);
		void ExecuteMouseHover(Object^ arg);
		void ExecuteMouseLeave(Object^ arg);
		void ExecuteMouseMove(Object^ arg);
		void ExecuteMouseUp(Object^ arg);
		void ExecuteMouseWheel(Object^ arg);
	};
}
#endif
