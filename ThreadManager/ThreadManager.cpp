#include "ThreadManager.h"

namespace ThreadManager
{
	ThreadManager::ThreadManager(IGLThreadWrapper^ glThreadWrapper, IAppThreadWrapper^ appThreadWrapper, ICallbackThreadWrapper^ callbackThreadWrapper)
	{
		glThread = glThreadWrapper;
		appThread = appThreadWrapper;
		callbackThread = callbackThreadWrapper;

		glThread->SetThreadManager(this);
		appThread->SetThreadManager(this);
		callbackThread->SetThreadManager(this);
	}

	ThreadManager::~ThreadManager()
	{
		TerminateThreads();
	}

	void ThreadManager::TerminateThreads()
	{
		TerminateGLThread();
		TerminateAppThread();
		TerminateCallbackThread();
	}

	void ThreadManager::StartGLThread(Object^ startArg) { glThread->StartThread(startArg); }

	void ThreadManager::TerminateGLThread()
	{
		glThread->TerminateThread();
	}

	int ThreadManager::GetGLThreadId()
	{
		return glThread->GetThreadId();
	}

	void ThreadManager::EnqueueOpenGLInit(IntPtr windowHandle, IntPtr deviceContext, IntPtr renderingContext) { glThread->EnqueueOpenGLInit(windowHandle, deviceContext, renderingContext); }
	void ThreadManager::EnqueueOpenGLResize(int width, int height) { glThread->EnqueueOpenGLResize(width, height); }
	void ThreadManager::EnqueueOpenGLRender() { glThread->EnqueueOpenGLRender(); }
	void ThreadManager::SwapOpenGLBuffers() { glThread->SwapOpenGLBuffers(); }

	void ThreadManager::StartAppThread(Object^ startArg) { appThread->StartThread(startArg); }

	void ThreadManager::TerminateAppThread()
	{
		appThread->TerminateThread();
	}

	int ThreadManager::GetAppThreadId()
	{
		return appThread->GetThreadId();
	}

	void ThreadManager::EnqueueStartGLThread(IntPtr handle, int width, int height)	{ appThread->EnqueueStartGLThread(handle, width, height); }
	void ThreadManager::EnqueueStartRenderingTimer()								{ appThread->EnqueueStartRenderingTimer(); }
	void ThreadManager::EnqueueKeyDown(Object^ e)			{ appThread->EnqueueKeyDown(e); }
	void ThreadManager::EnqueueKeyPress(Object^ e)			{ appThread->EnqueueKeyPress(e); }
	void ThreadManager::EnqueueKeyUp(Object^ e)				{ appThread->EnqueueKeyUp(e); }
	void ThreadManager::EnqueueMouseClick(Object^ e)		{ appThread->EnqueueMouseClick(e); }
	void ThreadManager::EnqueueMouseDoubleClick(Object^ e)	{ appThread->EnqueueMouseDoubleClick(e); }
	void ThreadManager::EnqueueMouseDown(Object^ e)			{ appThread->EnqueueMouseDown(e); }
	void ThreadManager::EnqueueMouseEnter(Object^ e)		{ appThread->EnqueueMouseEnter(e); }
	void ThreadManager::EnqueueMouseHover(Object^ e)		{ appThread->EnqueueMouseHover(e); }
	void ThreadManager::EnqueueMouseLeave(Object^ e)		{ appThread->EnqueueMouseLeave(e); }
	void ThreadManager::EnqueueMouseMove(Object^ e)			{ appThread->EnqueueMouseMove(e); }
	void ThreadManager::EnqueueMouseUp(Object^ e)			{ appThread->EnqueueMouseUp(e); }
	void ThreadManager::EnqueueMouseWheel(Object^ e)		{ appThread->EnqueueMouseWheel(e); }

	void ThreadManager::StartCallbackThread(Object^ startArg) { callbackThread->StartThread(startArg); }

	void ThreadManager::TerminateCallbackThread()
	{
		callbackThread->TerminateThread();
	}

	int ThreadManager::GetCallbackThreadId()
	{
		return callbackThread->GetThreadId();
	}

	void ThreadManager::EnqueueFullScreen() { callbackThread->EnqueueFullScreen(); }
	void ThreadManager::EnqueueCustomAction1(Object^ arg) { callbackThread->EnqueueCustomAction1(arg); }
	void ThreadManager::EnqueueCustomAction2(Object^ arg) { callbackThread->EnqueueCustomAction2(arg); }
	void ThreadManager::EnqueueCustomAction3(Object^ arg) { callbackThread->EnqueueCustomAction3(arg); }
	void ThreadManager::EnqueueCustomAction4(Object^ arg) { callbackThread->EnqueueCustomAction4(arg); }
	void ThreadManager::EnqueueCustomAction5(Object^ arg) { callbackThread->EnqueueCustomAction5(arg); }
	void ThreadManager::EnqueueCustomAction6(Object^ arg) { callbackThread->EnqueueCustomAction6(arg); }
	void ThreadManager::EnqueueCustomAction7(Object^ arg) { callbackThread->EnqueueCustomAction7(arg); }
	void ThreadManager::EnqueueCustomAction8(Object^ arg) { callbackThread->EnqueueCustomAction8(arg); }
}
