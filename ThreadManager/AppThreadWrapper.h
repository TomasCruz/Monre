#ifndef _AppThreadWrapper_h_
#define _AppThreadWrapper_h_

#include "IAppThreadWrapper.h"
#include "ThreadWrapperBase.h"
#include "AppThreadActionStrings.h"
#include "DelegateTypes.h"

namespace ThreadManager
{
	public ref class AppThreadWrapper abstract : public ThreadWrapperBase, public IAppThreadWrapper
	{
	public:
		AppThreadWrapper();
		virtual ~AppThreadWrapper();

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
	};
}
#endif
