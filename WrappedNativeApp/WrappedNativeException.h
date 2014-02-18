#ifndef _WrappedNativeException_h_
#define _WrappedNativeException_h_

#include "NativeException.h"
#using "ThreadManager.dll"

using namespace System;
using namespace ThreadManager;

namespace WrappedNativeApp
{
	public ref class WrappedNativeException : public NativeExceptionBase
	{
	public:
		WrappedNativeException(const NativeException &nativeExc);
		~WrappedNativeException();
		!WrappedNativeException();
		virtual String^ ToString() override;

	private:
		NativeException* nativeException;
	};
}
#endif
