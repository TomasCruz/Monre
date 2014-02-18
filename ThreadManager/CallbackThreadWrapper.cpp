#include "CallbackThreadWrapper.h"

namespace ThreadManager
{
	CallbackThreadWrapper::CallbackThreadWrapper() : ThreadWrapperBase() {}
	CallbackThreadWrapper::~CallbackThreadWrapper() {}

	void CallbackThreadWrapper::EnqueueFullScreen() { EnqueueDictionaryAction(CallbackThreadActionStrings::fullScreenString); }

#pragma region custom callback actions
	void CallbackThreadWrapper::EnqueueCustomAction1(Object^ arg) { EnqueueDictionaryAction(CallbackThreadActionStrings::customAction1String, arg); }
	void CallbackThreadWrapper::EnqueueCustomAction2(Object^ arg) { EnqueueDictionaryAction(CallbackThreadActionStrings::customAction2String, arg); }
	void CallbackThreadWrapper::EnqueueCustomAction3(Object^ arg) { EnqueueDictionaryAction(CallbackThreadActionStrings::customAction3String, arg); }
	void CallbackThreadWrapper::EnqueueCustomAction4(Object^ arg) { EnqueueDictionaryAction(CallbackThreadActionStrings::customAction4String, arg); }
	void CallbackThreadWrapper::EnqueueCustomAction5(Object^ arg) { EnqueueDictionaryAction(CallbackThreadActionStrings::customAction5String, arg); }
	void CallbackThreadWrapper::EnqueueCustomAction6(Object^ arg) { EnqueueDictionaryAction(CallbackThreadActionStrings::customAction6String, arg); }
	void CallbackThreadWrapper::EnqueueCustomAction7(Object^ arg) { EnqueueDictionaryAction(CallbackThreadActionStrings::customAction7String, arg); }
	void CallbackThreadWrapper::EnqueueCustomAction8(Object^ arg) { EnqueueDictionaryAction(CallbackThreadActionStrings::customAction8String, arg); }
#pragma endregion
}
