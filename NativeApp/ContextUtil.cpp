#include "ContextUtil.h"
#include "LoadUtil.h"
#include "NativeException.h"
#include <vector>

void ContextUtil::DestroyDummyAndCreateRealContext(LoadUtil& gl, HWND wnd, HDC* deviceContext, HGLRC* renderingContext)
{
	// destroy dummy context
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(*renderingContext);
	ReleaseDC(wnd, *deviceContext);

	// create real rendering context
	int pixelFormat[1];
	unsigned int formatCount;
	int result;
	std::vector<int> attributeListInt;
	std::vector<int> secondAttributeList;
	PIXELFORMATDESCRIPTOR pixelFormatDescriptor;

	// Get the device context for this window.
	*deviceContext = GetDC(wnd);
	if (!*deviceContext)
		throw NativeException("DestroyDummyAndCreateRealContext failure : GetDC");
	
	// Support for OpenGL rendering.
	attributeListInt.push_back(WGL_SUPPORT_OPENGL_ARB);
	attributeListInt.push_back(TRUE);

	// Support for rendering to a window.
	attributeListInt.push_back(WGL_DRAW_TO_WINDOW_ARB);
	attributeListInt.push_back(TRUE);

	// Support for hardware acceleration.
	attributeListInt.push_back(WGL_ACCELERATION_ARB);
	attributeListInt.push_back(WGL_FULL_ACCELERATION_ARB);

	// Support for 16 bit color.
	attributeListInt.push_back(WGL_COLOR_BITS_ARB);
	attributeListInt.push_back(16);

	// Support for 16 bit depth buffer.
	attributeListInt.push_back(WGL_DEPTH_BITS_ARB);
	attributeListInt.push_back(16);

	// Support for double buffer.
	attributeListInt.push_back(WGL_DOUBLE_BUFFER_ARB);
	attributeListInt.push_back(TRUE);

	// Support for swapping front and back buffer.
	attributeListInt.push_back(WGL_SWAP_METHOD_ARB);
	attributeListInt.push_back(WGL_SWAP_EXCHANGE_ARB);

	// Support for the RGBA pixel type.
	attributeListInt.push_back(WGL_PIXEL_TYPE_ARB);
	attributeListInt.push_back(WGL_TYPE_RGBA_ARB);

	// Support for a 8 bit stencil buffer.
	attributeListInt.push_back(WGL_STENCIL_BITS_ARB);
	attributeListInt.push_back(8);

	// Null terminate the attribute list.
	attributeListInt.push_back(0);

	// Query for a pixel format that fits the attributes we want.
	result = gl.wglChoosePixelFormatARB(*deviceContext, &attributeListInt[0], NULL, 1, pixelFormat, &formatCount);
	if (result != 1)
		throw NativeException("DestroyDummyAndCreateRealContext failure : wglChoosePixelFormatARB");

	// If the video card/display can handle our desired pixel format then we set it as the current one.
	result = SetPixelFormat(*deviceContext, pixelFormat[0], &pixelFormatDescriptor);
	if (result != 1)
		throw NativeException("DestroyDummyAndCreateRealContext failure : SetPixelFormat");

	// Set the 3.3 version of OpenGL in the attribute list.
	secondAttributeList.push_back(WGL_CONTEXT_MAJOR_VERSION_ARB);
	secondAttributeList.push_back(3);
	secondAttributeList.push_back(WGL_CONTEXT_MINOR_VERSION_ARB);
	secondAttributeList.push_back(3);
	secondAttributeList.push_back(WGL_CONTEXT_PROFILE_MASK_ARB);
	secondAttributeList.push_back(WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB);

	// Null terminate the attribute list.
	secondAttributeList.push_back(0);

	// Create a OpenGL 3.3 rendering context.
	*renderingContext = gl.wglCreateContextAttribsARB(*deviceContext, 0, &secondAttributeList[0]);
	if (*renderingContext == NULL)
		throw NativeException("DestroyDummyAndCreateRealContext failure : wglCreateContextAttribsARB");

	// Set the rendering context to active.
	result = wglMakeCurrent(*deviceContext, *renderingContext);
	if (result != 1)
		throw NativeException("DestroyDummyAndCreateRealContext failure : wglMakeCurrent");
}
