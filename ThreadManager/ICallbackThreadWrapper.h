#ifndef _ICallbackThreadWrapper_h_
#define _ICallbackThreadWrapper_h_

#include "IThreadWrapper.h"

namespace ThreadManager
{
	public interface class ICallbackThreadWrapper : public IThreadWrapper
	{
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
