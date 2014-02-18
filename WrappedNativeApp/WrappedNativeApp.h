#ifndef _WrappedNativeApp_h_
#define _WrappedNativeApp_h_

#include "NativeApplication.h"
#include "NativeException.h"
#include "WrappedNativeException.h"

#using <System.dll>
#using <System.Windows.Forms.dll>
#using "ThreadManager.dll"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Threading;
using namespace System::Diagnostics;
using namespace System::Windows::Forms;
using namespace ThreadManager;

namespace WrappedNativeApp
{
	public ref class WrappedNativeApplication : public ApplicationBase
	{
	private:
		NativeApplication* nativeApplication;
		IThreadManager^ threadManager;
		System::Timers::Timer^ renderingTimer;
		bool increaseOffset, decreaseOffset, increaseRotation, decreaseRotation;

		void renderingTimer_Elapsed(Object^ sender, System::Timers::ElapsedEventArgs^ e);

	public:
		WrappedNativeApplication();
		~WrappedNativeApplication();

		virtual void ExecuteInitialize(Object^ startArg) override;

		void ExecuteStartRenderingTimer();
		void SetThreadManager(IThreadManager^ paramThreadManager);

		virtual void ExecuteStartGLThread(IntPtr handle, int width, int height) override;
		virtual void ExecuteOpenGLInit(IntPtr windowHandle, IntPtr deviceContext, IntPtr renderingContext) override;
		virtual void ExecuteOpenGLDeinit() override;
		virtual void ExecuteResize(int width, int height) override;
		virtual void ExecuteRender() override;
		virtual void StartAppThread() override;
		virtual void ExecuteKeyDown(Object^ arg) override;
		virtual void ExecuteKeyUp(Object^ arg) override;

	protected:
		// Deallocate the native object on the finalizer
		!WrappedNativeApplication();
	};
}
#endif
