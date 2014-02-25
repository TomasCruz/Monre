#ifndef _ContextUtil_h_
#define _ContextUtil_h_

class LoadUtil;

#include <windows.h>

class ContextUtil
{
public:
	ContextUtil();
	~ContextUtil();

	void static DestroyDummyAndCreateRealContext(LoadUtil& gl, HWND wnd, HDC* deviceContext, HGLRC* renderingContext);
};
#endif
