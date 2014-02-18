#ifndef _IAppThreadWrapper_h_
#define _IAppThreadWrapper_h_

#include "IThreadWrapper.h"

namespace ThreadManager
{
	public interface class IAppThreadWrapper : public IThreadWrapper
	{
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
	};
}
#endif
