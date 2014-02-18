#ifndef _AppThreadActionStrings_h_
#define _AppThreadActionStrings_h_

using namespace System;

namespace ThreadManager
{
	public ref class AppThreadActionStrings
	{
	public:
		static String^ startGLThreadString = "startGLThread";
		static String^ nativeApplicationStartString = "nativeApplicationStart";
		static String^ nativeApplicationDestroyString = "nativeApplicationDestroy";
		static String^ startRenderingTimerString = "startRenderingTimer";

		// event strings
		static String^ keyDownString = "keyDown";
		static String^ keyPressString = "keyPress";
		static String^ keyUpString = "keyUp";
		static String^ mouseClickString = "mouseClick";
		static String^ mouseDoubleClickString = "mouseDoubleClick";
		static String^ mouseDownString = "mouseDown";
		static String^ mouseEnterString = "mouseEnter";
		static String^ mouseHoverString = "mouseHover";
		static String^ mouseLeaveString = "mouseLeave";
		static String^ mouseMoveString = "mouseMove";
		static String^ mouseUpString = "mouseUp";
		static String^ mouseWheelString = "mouseWheel";
	};
}
#endif
