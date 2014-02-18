#ifndef _ApplicationBase_h_
#define _ApplicationBase_h_

#include "IApplication.h"

namespace ThreadManager
{
	// this class exists primarily to enable default empty implementations of UI event handlers; user can override the needed handlers in a child class
	public ref class ApplicationBase abstract : public IApplication
	{
	public:
		virtual void ExecuteStartGLThread(IntPtr handle, int width, int height) = 0;
		virtual void ExecuteInitialize(Object^ startArg) = 0;
		virtual void ExecuteOpenGLInit(IntPtr windowHandle, IntPtr deviceContext, IntPtr renderingContext) = 0;
		virtual void ExecuteOpenGLDeinit() = 0;
		virtual void ExecuteResize(int width, int height) = 0;
		virtual void ExecuteRender() = 0;

		virtual void StartAppThread() = 0;
		virtual void ExecuteKeyDown(Object^ arg);
		virtual void ExecuteKeyPress(Object^ arg);
		virtual void ExecuteKeyUp(Object^ arg);
		virtual void ExecuteMouseClick(Object^ arg);
		virtual void ExecuteMouseDoubleClick(Object^ arg);
		virtual void ExecuteMouseDown(Object^ arg);
		virtual void ExecuteMouseEnter(Object^ arg);
		virtual void ExecuteMouseHover(Object^ arg);
		virtual void ExecuteMouseLeave(Object^ arg);
		virtual void ExecuteMouseMove(Object^ arg);
		virtual void ExecuteMouseUp(Object^ arg);
		virtual void ExecuteMouseWheel(Object^ arg);
	};
}
#endif
