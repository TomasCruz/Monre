#ifndef _IThreadWrapper_h_
#define _IThreadWrapper_h_

using namespace System;
using namespace System::Threading;
using namespace System::Collections::Generic;

#include "IThreadManager.h"

namespace ThreadManager
{
	public interface class IThreadWrapper
	{
		void CreateThread();
		void StartThread(Object^ startArg);
		void TerminateThread();
		int GetThreadId();
		void SetThreadManager(IThreadManager^ mgr);
	};
}
#endif
