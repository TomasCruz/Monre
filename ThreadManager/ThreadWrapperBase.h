#ifndef _ThreadWrapperBase_h_
#define _ThreadWrapperBase_h_

using namespace System;

#include "IThreadWrapper.h"
#include "IThreadManager.h"
#include "ActionItem.h"
#using <System.dll>

namespace ThreadManager
{
	public ref class ThreadWrapperBase abstract : public IThreadWrapper
	{
	public:
		ThreadWrapperBase();
		virtual ~ThreadWrapperBase();
		virtual int GetThreadId();
		virtual void CreateThread() = 0;
		virtual void StartThread(Object^ startArg);
		virtual void TerminateThread();
		virtual void SetThreadManager(IThreadManager^ mgr);

	protected:
		// members
		Thread^ thread;
		ManualResetEvent^ terminated;
		ManualResetEvent^ waitLock;
		Object^ actionQueueLock;
		Object^ doActionsLock;
		Queue<ActionItem^>^ actionQueue;
		Dictionary<String^, Delegate^>^ delegateDictionary;
		IThreadManager^ manager;

		// methods
		void EnqueueDictionaryAction(String^ delegateKeyString, ... array<Object^>^ args);
		void EnqueueAction(Delegate^ actionDelegate, ... array<Object^>^ args);
		void DoActions();
		virtual void ExecuteAction(ActionItem^ actionItem);
		virtual void InitThread() = 0;
		virtual void DeinitThread() = 0;
		void DeleteThread();
		virtual void ProcessThreadList(List<Object^>^ threadList);
		virtual void ExecuteThread(Object^ startArg);
	};
}
#endif
