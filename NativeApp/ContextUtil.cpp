#include "ContextUtil.h"
#include "LoadUtil.h"

bool ContextUtil::DestroyDummyAndCreateRealContext(LoadUtil& gl, HWND wnd, HDC* deviceContext, HGLRC* renderingContext)
{
	// destroy dummy context
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(*renderingContext);
	ReleaseDC(wnd, *deviceContext);

	// create real rendering context
	int attributeListInt[19];
	int pixelFormat[1];
	unsigned int formatCount;
	int result;
	PIXELFORMATDESCRIPTOR pixelFormatDescriptor;
	int attributeList[7];

	// Get the device context for this window.
	*deviceContext = GetDC(wnd);
	if (!*deviceContext)
	{
		return false;
	}
	
	// Support for OpenGL rendering.
	attributeListInt[0] = WGL_SUPPORT_OPENGL_ARB;
	attributeListInt[1] = TRUE;

	// Support for rendering to a window.
	attributeListInt[2] = WGL_DRAW_TO_WINDOW_ARB;
	attributeListInt[3] = TRUE;

	// Support for hardware acceleration.
	attributeListInt[4] = WGL_ACCELERATION_ARB;
	attributeListInt[5] = WGL_FULL_ACCELERATION_ARB;

	// Support for 32 bit color.
	attributeListInt[6] = WGL_COLOR_BITS_ARB;
	attributeListInt[7] = 32;

	// Support for 24 bit depth buffer.
	attributeListInt[8] = WGL_DEPTH_BITS_ARB;
	attributeListInt[9] = 24;

	// Support for double buffer.
	attributeListInt[10] = WGL_DOUBLE_BUFFER_ARB;
	attributeListInt[11] = TRUE;

	// Support for swapping front and back buffer.
	attributeListInt[12] = WGL_SWAP_METHOD_ARB;
	attributeListInt[13] = WGL_SWAP_EXCHANGE_ARB;

	// Support for the RGBA pixel type.
	attributeListInt[14] = WGL_PIXEL_TYPE_ARB;
	attributeListInt[15] = WGL_TYPE_RGBA_ARB;

	// Support for a 8 bit stencil buffer.
	attributeListInt[16] = WGL_STENCIL_BITS_ARB;
	attributeListInt[17] = 8;

	// Null terminate the attribute list.
	attributeListInt[18] = 0;

	// Query for a pixel format that fits the attributes we want.
	result = gl.wglChoosePixelFormatARB(*deviceContext, attributeListInt, NULL, 1, pixelFormat, &formatCount);
	if (result != 1)
	{
		return false;
	}

	// If the video card/display can handle our desired pixel format then we set it as the current one.
	result = SetPixelFormat(*deviceContext, pixelFormat[0], &pixelFormatDescriptor);
	if (result != 1)
	{
		return false;
	}

	// Set the 3.3 version of OpenGL in the attribute list.
	attributeList[0] = WGL_CONTEXT_MAJOR_VERSION_ARB;
	attributeList[1] = 3;
	attributeList[2] = WGL_CONTEXT_MINOR_VERSION_ARB;
	attributeList[3] = 3;
	attributeList[4] = WGL_CONTEXT_PROFILE_MASK_ARB;
	attributeList[5] = WGL_CONTEXT_CORE_PROFILE_BIT_ARB;

	// Null terminate the attribute list.
	attributeList[6] = 0;

	// Create a OpenGL 3.3 rendering context.
	*renderingContext = gl.wglCreateContextAttribsARB(*deviceContext, 0, attributeList);
	if (*renderingContext == NULL)
	{
		return false;
	}

	// Set the rendering context to active.
	result = wglMakeCurrent(*deviceContext, *renderingContext);
	if (result != 1)
	{
		return false;
	}
	
	return true;
}
