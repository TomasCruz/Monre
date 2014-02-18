#include "WrappedNativeException.h"

namespace WrappedNativeApp
{
	WrappedNativeException::WrappedNativeException(const NativeException &nativeExc) : nativeException(new NativeException(nativeExc))
	{
	}

	WrappedNativeException::~WrappedNativeException()
	{
		this->!WrappedNativeException();
	}

	WrappedNativeException::!WrappedNativeException()
	{
		delete nativeException;
	}

	String^ WrappedNativeException::ToString()
	{
		return gcnew System::String(nativeException->GetInfo().c_str());
	}
}
