#ifndef _GLThreadActionStrings_h_
#define _GLThreadActionStrings_h_

using namespace System;

namespace ThreadManager
{
	public ref class GLThreadActionStrings
	{
	public:
		static String^ glInitString = "glInit";
		static String^ glDeinitString = "glDeinit";
		static String^ glResizeString = "glResize";
		static String^ glRenderString = "glRender";
	};
}
#endif
