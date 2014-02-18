#include "AppThreadWrapper.h"

namespace ThreadManager
{
	AppThreadWrapper::AppThreadWrapper() : ThreadWrapperBase() {}
	AppThreadWrapper::~AppThreadWrapper() {}

	void AppThreadWrapper::EnqueueStartGLThread(IntPtr handle, int width, int height)	{ EnqueueDictionaryAction(AppThreadActionStrings::startGLThreadString, handle, width, height); }
	void AppThreadWrapper::EnqueueStartRenderingTimer()									{ EnqueueDictionaryAction(AppThreadActionStrings::startRenderingTimerString); }

#pragma region Enqueue UI actions
	void AppThreadWrapper::EnqueueKeyDown(Object^ e)			{ EnqueueDictionaryAction(AppThreadActionStrings::keyDownString, e); }
	void AppThreadWrapper::EnqueueKeyPress(Object^ e)			{ EnqueueDictionaryAction(AppThreadActionStrings::keyPressString, e); }
	void AppThreadWrapper::EnqueueKeyUp(Object^ e)				{ EnqueueDictionaryAction(AppThreadActionStrings::keyUpString, e); }
	void AppThreadWrapper::EnqueueMouseClick(Object^ e)			{ EnqueueDictionaryAction(AppThreadActionStrings::mouseClickString, e); }
	void AppThreadWrapper::EnqueueMouseDoubleClick(Object^ e)	{ EnqueueDictionaryAction(AppThreadActionStrings::mouseDoubleClickString, e); }
	void AppThreadWrapper::EnqueueMouseDown(Object^ e)			{ EnqueueDictionaryAction(AppThreadActionStrings::mouseDownString, e); }
	void AppThreadWrapper::EnqueueMouseEnter(Object^ e)			{ EnqueueDictionaryAction(AppThreadActionStrings::mouseEnterString, e); }
	void AppThreadWrapper::EnqueueMouseHover(Object^ e)			{ EnqueueDictionaryAction(AppThreadActionStrings::mouseHoverString, e); }
	void AppThreadWrapper::EnqueueMouseLeave(Object^ e)			{ EnqueueDictionaryAction(AppThreadActionStrings::mouseLeaveString, e); }
	void AppThreadWrapper::EnqueueMouseMove(Object^ e)			{ EnqueueDictionaryAction(AppThreadActionStrings::mouseMoveString, e); }
	void AppThreadWrapper::EnqueueMouseUp(Object^ e)			{ EnqueueDictionaryAction(AppThreadActionStrings::mouseUpString, e); }
	void AppThreadWrapper::EnqueueMouseWheel(Object^ e)			{ EnqueueDictionaryAction(AppThreadActionStrings::mouseWheelString, e); }
#pragma endregion
}
