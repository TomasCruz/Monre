#ifndef _CallbackThreadWrapper_h_
#define _CallbackThreadWrapper_h_

#include "ICallbackThreadWrapper.h"
#include "ThreadWrapperBase.h"
#include "CallbackThreadActionStrings.h"

namespace ThreadManager
{
	public ref class CallbackThreadWrapper abstract : public ThreadWrapperBase, public ICallbackThreadWrapper
	{
	public:
		CallbackThreadWrapper();
		virtual ~CallbackThreadWrapper();

		virtual void EnqueueFullScreen();
		virtual void EnqueueCustomAction1(Object^ arg);
		virtual void EnqueueCustomAction2(Object^ arg);
		virtual void EnqueueCustomAction3(Object^ arg);
		virtual void EnqueueCustomAction4(Object^ arg);
		virtual void EnqueueCustomAction5(Object^ arg);
		virtual void EnqueueCustomAction6(Object^ arg);
		virtual void EnqueueCustomAction7(Object^ arg);
		virtual void EnqueueCustomAction8(Object^ arg);
	};
}
#endif

