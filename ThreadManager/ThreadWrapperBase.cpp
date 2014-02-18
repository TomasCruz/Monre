#include "ThreadWrapperBase.h"
#include "NativeExceptionBase.h"

#using <System.Windows.Forms.dll>

namespace ThreadManager
{
	ThreadWrapperBase::ThreadWrapperBase()
	{
		actionQueue = gcnew Queue<ActionItem^>();
		actionQueueLock = gcnew Object();
		doActionsLock = gcnew Object();
		terminated = gcnew ManualResetEvent(false);
		waitLock = gcnew ManualResetEvent(false);
		delegateDictionary = gcnew Dictionary<String^, Delegate^>();
		CreateThread();
	}

	void ThreadWrapperBase::StartThread(Object^ startArg)
	{
		thread->Start(startArg);
	}

	void ThreadWrapperBase::TerminateThread()
	{
		// set "terminated" to indicate we want to finish the thread
		if (terminated)
			terminated->Set();

		waitLock->Set();

		// wait until the thread finishes
		if (thread != nullptr && thread->ThreadState == ThreadState::Running)
		{
			thread->Join();
			thread = nullptr;
		}
	}

	ThreadWrapperBase::~ThreadWrapperBase()
	{
		TerminateThread();
		DeleteThread();
	}

	void ThreadWrapperBase::DeleteThread()
	{
		if (thread != nullptr)
		{
			delete thread;
			thread = nullptr;
		}
	}

	int ThreadWrapperBase::GetThreadId()
	{
		// "Thread ID is unique per process during a thread's lifecycle. After the thread terminates, its number can be reused."
		// as per http://stackoverflow.com/questions/2221908/how-unique-is-managedthreadid
		// Threads in this application are terminated on closing OpenGLForm,
		// so it's OK to identify threads by their ManagedThreadId
		return thread->ManagedThreadId;
	}

	void ThreadWrapperBase::SetThreadManager(IThreadManager^ mgr)
	{
		manager = mgr;
	}

	void ThreadWrapperBase::EnqueueDictionaryAction(String^ delegateKeyString, ... array<Object^>^ args)
	{
		if (!delegateDictionary->ContainsKey(delegateKeyString))
			return;

		EnqueueAction(delegateDictionary[delegateKeyString], args);
	}

	void ThreadWrapperBase::EnqueueAction(Delegate^ actionDelegate, ... array<Object^>^ args)
	{
		// avoid cross thread collisions
		Monitor::Enter(actionQueueLock);
		try 
		{
			ActionItem^ actionItem = gcnew ActionItem(actionDelegate, args);
			actionQueue->Enqueue(actionItem);
			waitLock->Set();
		}
		finally
		{
			Monitor::Exit(actionQueueLock);
		}		
	}

	void ThreadWrapperBase::DoActions()
	{
		Queue<ActionItem^>^ temporaryActionQueue;
		Monitor::Enter(actionQueueLock);
		try
		{
			temporaryActionQueue = gcnew Queue<ActionItem^>(actionQueue);
			actionQueue->Clear();
			waitLock->Reset();
		}
		finally
		{
			Monitor::Exit(actionQueueLock);
		}

		// execute actions
		Monitor::Enter(doActionsLock);
		try
		{
			while (!terminated->WaitOne(0) && temporaryActionQueue->Count > 0)
			{
				ActionItem^ actionItem = temporaryActionQueue->Dequeue();
				ExecuteAction(actionItem);
			}
		}
		finally
		{
			Monitor::Exit(doActionsLock);
		}
	}

	void ThreadWrapperBase::ExecuteAction(ActionItem^ actionItem)
	{
		// Exception handling below can be used to debug which actions were invoked on wrong thread

		try { actionItem->ActionDelegate->DynamicInvoke( actionItem->Arguments ); }
		catch(System::Reflection::TargetInvocationException^ tie) { System::Windows::Forms::MessageBox::Show(tie->ToString()); }
		catch(System::Reflection::TargetParameterCountException^ tpce) { System::Windows::Forms::MessageBox::Show(tpce->ToString()); }
		catch(NativeExceptionBase^ e) { System::Windows::Forms::MessageBox::Show(e->ToString()); }
	}

	void ThreadWrapperBase::ProcessThreadList(List<Object^>^ threadList)
	{
		KeyValuePair<String^, Delegate^>^ currKVPair;
		for (int i = 0; i < threadList->Count; i++)
		{
			currKVPair = (KeyValuePair<String^, Delegate^>^)threadList[i];
			delegateDictionary->Add(currKVPair->Key, currKVPair->Value);
		}
	}

	void ThreadWrapperBase::ExecuteThread(Object^ startArg)
	{
		ProcessThreadList((List<Object^>^)startArg);
		InitThread();

		// do until the termination was not requested
		while (!terminated->WaitOne(0))
		{
			// renderingTimer will enqueue rendering periodically
			DoActions();

			// wait for the new events
			waitLock->WaitOne();
		}

		DeinitThread();
	}
}
