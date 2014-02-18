#include "LoadUtil.h"

GLES2ACTIVETEXTUREPROC glActiveTexture;
GLES2ATTACHSHADERPROC glAttachShader;
GLES2BINDATTRIBLOCATIONPROC glBindAttribLocation;
GLES2BINDBUFFERPROC glBindBuffer;
GLES2BINDFRAMEBUFFERPROC glBindFramebuffer;
GLES2BINDRENDERBUFFERPROC glBindRenderbuffer;
//GLES2BINDTEXTUREPROC glBindTexture; // defined in gl.h
GLES2BLENDCOLORPROC glBlendColor;
GLES2BLENDEQUATIONPROC glBlendEquation;
GLES2BLENDEQUATIONSEPARATEPROC glBlendEquationSeparate;
//glBlendFunc // defined in gl.h
GLES2BLENDFUNCSEPARATEPROC glBlendFuncSeparate;
GLES2BUFFERDATAPROC glBufferData;
GLES2BUFFERSUBDATAPROC glBufferSubData;
GLES2CHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus;
//glClear // defined in gl.h
//glClearColor // defined in gl.h
GLES2CLEARDEPTHFPROC glClearDepthf;
//glClearStencil // defined in gl.h
//glColorMask // defined in gl.h
GLES2COMPILESHADERPROC glCompileShader;
GLES2COMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D;
GLES2COMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D;
//glCopyTexImage2D; // defined in gl.h
//glCopyTexSubImage2D; // defined in gl.h
GLES2CREATEPROGRAMPROC glCreateProgram;
GLES2CREATESHADERPROC glCreateShader;
//glCullFace; // defined in gl.h
GLES2DELETEBUFFERSPROC glDeleteBuffers;
GLES2DELETEFRAMEBUFFERSPROC glDeleteFramebuffers;
GLES2DELETEPROGRAMPROC glDeleteProgram;
GLES2DELETERENDERBUFFERSPROC glDeleteRenderbuffers;
GLES2DELETESHADERPROC glDeleteShader;
//glDeleteTextures; // defined in gl.h
//glDepthFunc; // defined in gl.h
//glDepthMask; // defined in gl.h
GLES2DEPTHRANGEFPROC glDepthRangef;
GLES2DETACHSHADERPROC glDetachShader;
//glDisable; // defined in gl.h
GLES2DISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
//glDrawArrays; // defined in gl.h
//glDrawElements; // defined in gl.h
//glEnable // defined in gl.h
GLES2ENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
//glFinish // defined in gl.h
//glFlush // defined in gl.h
GLES2FRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer;
GLES2FRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D;
//glFrontFace // defined in gl.h
GLES2GENBUFFERSPROC glGenBuffers;
GLES2GENFRAMEBUFFERSPROC glGenFramebuffers;
GLES2GENRENDERBUFFERSPROC glGenRenderbuffers;
//glGenTextures // defined in gl.h
GLES2GENERATEMIPMAPPROC glGenerateMipmap;
//glGetBooleanv; // defined in gl.h
//glGetFloatv; // defined in gl.h
//glGetIntegerv; // defined in gl.h
GLES2GETACTIVEATTRIBPROC glGetActiveAttrib;
GLES2GETACTIVEUNIFORMPROC glGetActiveUniform;
GLES2GETATTACHEDSHADERSPROC glGetAttachedShaders;
GLES2GETATTRIBLOCATIONPROC glGetAttribLocation;
GLES2GETBUFFERPARAMETERIVPROC glGetBufferParameteriv;
//glGetError; // defined in gl.h
GLES2GETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv;
GLES2GETPROGRAMINFOLOGPROC glGetProgramInfoLog;
GLES2GETPROGRAMIVPROC glGetProgramiv;
GLES2GETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv;
GLES2GETSHADERINFOLOGPROC glGetShaderInfoLog;
GLES2GETSHADERPRECISIONFORMATPROC glGetShaderPrecisionFormat;
GLES2GETSHADERSOURCEPROC glGetShaderSource;
GLES2GETSHADERIVPROC glGetShaderiv;
//glGetString; // defined in gl.h
//glGetTexParameterfv; // defined in gl.h
//glGetTexParameteriv; // defined in gl.h
GLES2GETUNIFORMFVPROC glGetUniformfv;
GLES2GETUNIFORMIVPROC glGetUniformiv;
GLES2GETUNIFORMLOCATIONPROC glGetUniformLocation;
GLES2GETVERTEXATTRIBFVPROC glGetVertexAttribfv;
GLES2GETVERTEXATTRIBIVPROC glGetVertexAttribiv;
GLES2GETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv;
//glHint; // defined in gl.h
GLES2ISBUFFERPROC glIsBuffer;
//glIsEnabled; // defined in gl.h
GLES2ISFRAMEBUFFERPROC glIsFramebuffer;
GLES2ISPROGRAMPROC glIsProgram;
GLES2ISRENDERBUFFERPROC glIsRenderbuffer;
GLES2ISSHADERPROC glIsShader;
//glIsTexture; // defined in gl.h
//glLineWidth; // defined in gl.h
GLES2LINKPROGRAMPROC glLinkProgram;
//glPixelStorei; // defined in gl.h
//glPolygonOffset; // defined in gl.h
//glReadPixels; // defined in gl.h
GLES2RELEASESHADERCOMPILERPROC glReleaseShaderCompiler;
GLES2RENDERBUFFERSTORAGEPROC glRenderbufferStorage;
GLES2SAMPLECOVERAGEPROC glSampleCoverage;
//glScissor; // defined in gl.h
GLES2SHADERBINARYPROC glShaderBinary;
GLES2SHADERSOURCEPROC glShaderSource;
//glStencilFunc; // defined in gl.h
GLES2STENCILFUNCSEPARATEPROC glStencilFuncSeparate;
//glStencilMask; // defined in gl.h
GLES2STENCILMASKSEPARATEPROC glStencilMaskSeparate;
//glStencilOp; // defined in gl.h
GLES2STENCILOPSEPARATEPROC glStencilOpSeparate;
//glTexImage2D; // defined in gl.h
//glTexParameterf; // defined in gl.h
//glTexParameterfv; // defined in gl.h
//glTexParameteri; // defined in gl.h
//glTexParameteriv; // defined in gl.h
//glTexSubImage2D; // defined in gl.h
GLES2UNIFORM1FPROC glUniform1f;
GLES2UNIFORM2FPROC glUniform2f;
GLES2UNIFORM3FPROC glUniform3f;
GLES2UNIFORM4FPROC glUniform4f;
GLES2UNIFORM1IPROC glUniform1i;
GLES2UNIFORM2IPROC glUniform2i;
GLES2UNIFORM3IPROC glUniform3i;
GLES2UNIFORM4IPROC glUniform4i;
GLES2UNIFORM1FVPROC glUniform1fv;
GLES2UNIFORM2FVPROC glUniform2fv;
GLES2UNIFORM3FVPROC glUniform3fv;
GLES2UNIFORM4FVPROC glUniform4fv;
GLES2UNIFORM1IVPROC glUniform1iv;
GLES2UNIFORM2IVPROC glUniform2iv;
GLES2UNIFORM3IVPROC glUniform3iv;
GLES2UNIFORM4IVPROC glUniform4iv;
GLES2UNIFORMMATRIX2FVPROC glUniformMatrix2fv;
GLES2UNIFORMMATRIX3FVPROC glUniformMatrix3fv;
GLES2UNIFORMMATRIX4FVPROC glUniformMatrix4fv;
GLES2USEPROGRAMPROC glUseProgram;
GLES2VALIDATEPROGRAMPROC glValidateProgram;
GLES2VERTEXATTRIB1FPROC glVertexAttrib1f;
GLES2VERTEXATTRIB2FPROC glVertexAttrib2f;
GLES2VERTEXATTRIB3FPROC glVertexAttrib3f;
GLES2VERTEXATTRIB4FPROC glVertexAttrib4f;
GLES2VERTEXATTRIB1FVPROC glVertexAttrib1fv;
GLES2VERTEXATTRIB2FVPROC glVertexAttrib2fv;
GLES2VERTEXATTRIB3FVPROC glVertexAttrib3fv;
GLES2VERTEXATTRIB4FVPROC glVertexAttrib4fv;
GLES2VERTEXATTRIBPOINTERPROC glVertexAttribPointer;
//glViewport; // defined in gl.h

#define LOAD_AND_TEST_FUNCPTR(funcPtrType, funcPtr) funcPtr = (funcPtrType)wglGetProcAddress((LPCSTR)#funcPtr); if (!TestPointer((void*)funcPtr)) return false

LoadUtil::LoadUtil() {}
LoadUtil::~LoadUtil() {}

int LoadUtil::TestPointer(const void *pTest)
{
	ptrdiff_t iTest;
	if(!pTest) return 0;
	iTest = (ptrdiff_t)pTest;
	
	if(iTest == 1 || iTest == 2 || iTest == 3 || iTest == -1) return 0;
	
	return 1;
}

bool LoadUtil::LoadOpenGLES2Functions()
{
	// wgl stuff
	LOAD_AND_TEST_FUNCPTR(PFNWGLCHOOSEPIXELFORMATARBPROC, wglChoosePixelFormatARB);
	LOAD_AND_TEST_FUNCPTR(PFNWGLCREATECONTEXTATTRIBSARBPROC, wglCreateContextAttribsARB);
	LOAD_AND_TEST_FUNCPTR(PFNWGLSWAPINTERVALEXTPROC, wglSwapIntervalEXT);


	// Vertex Array Object stuff
	LOAD_AND_TEST_FUNCPTR(PFNGLBINDVERTEXARRAYPROC, glBindVertexArray);
	LOAD_AND_TEST_FUNCPTR(PFNGLDELETEVERTEXARRAYSPROC, glDeleteVertexArrays);
	LOAD_AND_TEST_FUNCPTR(PFNGLGENVERTEXARRAYSPROC, glGenVertexArrays);
	LOAD_AND_TEST_FUNCPTR(PFNGLISVERTEXARRAYPROC, glIsVertexArray);


	// OpenGL ES 2.0 stuff
	LOAD_AND_TEST_FUNCPTR(GLES2ACTIVETEXTUREPROC, glActiveTexture);
	LOAD_AND_TEST_FUNCPTR(GLES2ATTACHSHADERPROC, glAttachShader);
	LOAD_AND_TEST_FUNCPTR(GLES2BINDATTRIBLOCATIONPROC, glBindAttribLocation);
	LOAD_AND_TEST_FUNCPTR(GLES2BINDBUFFERPROC, glBindBuffer);
	LOAD_AND_TEST_FUNCPTR(GLES2BINDFRAMEBUFFERPROC, glBindFramebuffer);
	LOAD_AND_TEST_FUNCPTR(GLES2BINDRENDERBUFFERPROC, glBindRenderbuffer);
	//glBindTexture; // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2BLENDCOLORPROC, glBlendColor);
	LOAD_AND_TEST_FUNCPTR(GLES2BLENDEQUATIONPROC, glBlendEquation);
	LOAD_AND_TEST_FUNCPTR(GLES2BLENDEQUATIONSEPARATEPROC, glBlendEquationSeparate);
	//glBlendFunc // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2BLENDFUNCSEPARATEPROC, glBlendFuncSeparate);
	LOAD_AND_TEST_FUNCPTR(GLES2BUFFERDATAPROC, glBufferData);
	LOAD_AND_TEST_FUNCPTR(GLES2BUFFERSUBDATAPROC, glBufferSubData);
	LOAD_AND_TEST_FUNCPTR(GLES2CHECKFRAMEBUFFERSTATUSPROC, glCheckFramebufferStatus);
	//glClear // defined in gl.h
	//glClearColor // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2CLEARDEPTHFPROC, glClearDepthf);
	//glClearStencil // defined in gl.h
	//glColorMask // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2COMPILESHADERPROC, glCompileShader);
	LOAD_AND_TEST_FUNCPTR(GLES2COMPRESSEDTEXIMAGE2DPROC, glCompressedTexImage2D);
	LOAD_AND_TEST_FUNCPTR(GLES2COMPRESSEDTEXSUBIMAGE2DPROC, glCompressedTexSubImage2D);
	//glCopyTexImage2D; // defined in gl.h
	//glCopyTexSubImage2D; // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2CREATEPROGRAMPROC, glCreateProgram);
	LOAD_AND_TEST_FUNCPTR(GLES2CREATESHADERPROC, glCreateShader);
	//glCullFace; // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2DELETEBUFFERSPROC, glDeleteBuffers);
	LOAD_AND_TEST_FUNCPTR(GLES2DELETEFRAMEBUFFERSPROC, glDeleteFramebuffers);
	LOAD_AND_TEST_FUNCPTR(GLES2DELETEPROGRAMPROC, glDeleteProgram);
	LOAD_AND_TEST_FUNCPTR(GLES2DELETERENDERBUFFERSPROC, glDeleteRenderbuffers);
	LOAD_AND_TEST_FUNCPTR(GLES2DELETESHADERPROC, glDeleteShader);
	//glDeleteTextures; // defined in gl.h
	//glDepthFunc; // defined in gl.h
	//glDepthMask; // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2DEPTHRANGEFPROC, glDepthRangef);
	LOAD_AND_TEST_FUNCPTR(GLES2DETACHSHADERPROC, glDetachShader);
	//glDisable; // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2DISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArray);
	//glDrawArrays; // defined in gl.h
	//glDrawElements; // defined in gl.h
	//glEnable // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2ENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray);
	//glFinish // defined in gl.h
	//glFlush // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2FRAMEBUFFERRENDERBUFFERPROC, glFramebufferRenderbuffer);
	LOAD_AND_TEST_FUNCPTR(GLES2FRAMEBUFFERTEXTURE2DPROC, glFramebufferTexture2D);
	//glFrontFace // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2GENBUFFERSPROC, glGenBuffers);
	LOAD_AND_TEST_FUNCPTR(GLES2GENFRAMEBUFFERSPROC, glGenFramebuffers);
	LOAD_AND_TEST_FUNCPTR(GLES2GENRENDERBUFFERSPROC, glGenRenderbuffers);
	//glGenTextures // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2GENERATEMIPMAPPROC, glGenerateMipmap);
	//glGetBooleanv; // defined in gl.h
	//glGetFloatv; // defined in gl.h
	//glGetIntegerv; // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2GETACTIVEATTRIBPROC, glGetActiveAttrib);
	LOAD_AND_TEST_FUNCPTR(GLES2GETACTIVEUNIFORMPROC, glGetActiveUniform);
	LOAD_AND_TEST_FUNCPTR(GLES2GETATTACHEDSHADERSPROC, glGetAttachedShaders);
	LOAD_AND_TEST_FUNCPTR(GLES2GETATTRIBLOCATIONPROC, glGetAttribLocation);
	LOAD_AND_TEST_FUNCPTR(GLES2GETBUFFERPARAMETERIVPROC, glGetBufferParameteriv);
	//glGetError; // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2GETFRAMEBUFFERATTACHMENTPARAMETERIVPROC, glGetFramebufferAttachmentParameteriv);
	LOAD_AND_TEST_FUNCPTR(GLES2GETPROGRAMINFOLOGPROC, glGetProgramInfoLog);
	LOAD_AND_TEST_FUNCPTR(GLES2GETPROGRAMIVPROC, glGetProgramiv);
	LOAD_AND_TEST_FUNCPTR(GLES2GETRENDERBUFFERPARAMETERIVPROC, glGetRenderbufferParameteriv);
	LOAD_AND_TEST_FUNCPTR(GLES2GETSHADERINFOLOGPROC, glGetShaderInfoLog);
	LOAD_AND_TEST_FUNCPTR(GLES2GETSHADERPRECISIONFORMATPROC, glGetShaderPrecisionFormat);
	LOAD_AND_TEST_FUNCPTR(GLES2GETSHADERSOURCEPROC, glGetShaderSource);
	LOAD_AND_TEST_FUNCPTR(GLES2GETSHADERIVPROC, glGetShaderiv);
	//glGetString; // defined in gl.h
	//glGetTexParameterfv; // defined in gl.h
	//glGetTexParameteriv; // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2GETUNIFORMFVPROC, glGetUniformfv);
	LOAD_AND_TEST_FUNCPTR(GLES2GETUNIFORMIVPROC, glGetUniformiv);
	LOAD_AND_TEST_FUNCPTR(GLES2GETUNIFORMLOCATIONPROC, glGetUniformLocation);
	LOAD_AND_TEST_FUNCPTR(GLES2GETVERTEXATTRIBFVPROC, glGetVertexAttribfv);
	LOAD_AND_TEST_FUNCPTR(GLES2GETVERTEXATTRIBIVPROC, glGetVertexAttribiv);
	LOAD_AND_TEST_FUNCPTR(GLES2GETVERTEXATTRIBPOINTERVPROC, glGetVertexAttribPointerv);
	//glHint; // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2ISBUFFERPROC, glIsBuffer);
	//glIsEnabled; // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2ISFRAMEBUFFERPROC, glIsFramebuffer);
	LOAD_AND_TEST_FUNCPTR(GLES2ISPROGRAMPROC, glIsProgram);
	LOAD_AND_TEST_FUNCPTR(GLES2ISRENDERBUFFERPROC, glIsRenderbuffer);
	LOAD_AND_TEST_FUNCPTR(GLES2ISSHADERPROC, glIsShader);
	//glIsTexture; // defined in gl.h
	//glLineWidth; // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2LINKPROGRAMPROC, glLinkProgram);
	//glPixelStorei; // defined in gl.h
	//glPolygonOffset; // defined in gl.h
	//glReadPixels; // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2RELEASESHADERCOMPILERPROC, glReleaseShaderCompiler);
	LOAD_AND_TEST_FUNCPTR(GLES2RENDERBUFFERSTORAGEPROC, glRenderbufferStorage);
	LOAD_AND_TEST_FUNCPTR(GLES2SAMPLECOVERAGEPROC, glSampleCoverage);
	//glScissor; // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2SHADERBINARYPROC, glShaderBinary);
	LOAD_AND_TEST_FUNCPTR(GLES2SHADERSOURCEPROC, glShaderSource);
	//glStencilFunc; // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2STENCILFUNCSEPARATEPROC, glStencilFuncSeparate);
	//glStencilMask; // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2STENCILMASKSEPARATEPROC, glStencilMaskSeparate);
	//glStencilOp; // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2STENCILOPSEPARATEPROC, glStencilOpSeparate);
	//glTexImage2D; // defined in gl.h
	//glTexParameterf; // defined in gl.h
	//glTexParameterfv; // defined in gl.h
	//glTexParameteri; // defined in gl.h
	//glTexParameteriv; // defined in gl.h
	//glTexSubImage2D; // defined in gl.h
	LOAD_AND_TEST_FUNCPTR(GLES2UNIFORM1FPROC, glUniform1f);
	LOAD_AND_TEST_FUNCPTR(GLES2UNIFORM2FPROC, glUniform2f);
	LOAD_AND_TEST_FUNCPTR(GLES2UNIFORM3FPROC, glUniform3f);
	LOAD_AND_TEST_FUNCPTR(GLES2UNIFORM4FPROC, glUniform4f);
	LOAD_AND_TEST_FUNCPTR(GLES2UNIFORM1IPROC, glUniform1i);
	LOAD_AND_TEST_FUNCPTR(GLES2UNIFORM2IPROC, glUniform2i);
	LOAD_AND_TEST_FUNCPTR(GLES2UNIFORM3IPROC, glUniform3i);
	LOAD_AND_TEST_FUNCPTR(GLES2UNIFORM4IPROC, glUniform4i);
	LOAD_AND_TEST_FUNCPTR(GLES2UNIFORM1FVPROC, glUniform1fv);
	LOAD_AND_TEST_FUNCPTR(GLES2UNIFORM2FVPROC, glUniform2fv);
	LOAD_AND_TEST_FUNCPTR(GLES2UNIFORM3FVPROC, glUniform3fv);
	LOAD_AND_TEST_FUNCPTR(GLES2UNIFORM4FVPROC, glUniform4fv);
	LOAD_AND_TEST_FUNCPTR(GLES2UNIFORM1IVPROC, glUniform1iv);
	LOAD_AND_TEST_FUNCPTR(GLES2UNIFORM2IVPROC, glUniform2iv);
	LOAD_AND_TEST_FUNCPTR(GLES2UNIFORM3IVPROC, glUniform3iv);
	LOAD_AND_TEST_FUNCPTR(GLES2UNIFORM4IVPROC, glUniform4iv);
	LOAD_AND_TEST_FUNCPTR(GLES2UNIFORMMATRIX2FVPROC, glUniformMatrix2fv);
	LOAD_AND_TEST_FUNCPTR(GLES2UNIFORMMATRIX3FVPROC, glUniformMatrix3fv);
	LOAD_AND_TEST_FUNCPTR(GLES2UNIFORMMATRIX4FVPROC, glUniformMatrix4fv);
	LOAD_AND_TEST_FUNCPTR(GLES2USEPROGRAMPROC, glUseProgram);
	LOAD_AND_TEST_FUNCPTR(GLES2VALIDATEPROGRAMPROC, glValidateProgram);
	LOAD_AND_TEST_FUNCPTR(GLES2VERTEXATTRIB1FPROC, glVertexAttrib1f);
	LOAD_AND_TEST_FUNCPTR(GLES2VERTEXATTRIB2FPROC, glVertexAttrib2f);
	LOAD_AND_TEST_FUNCPTR(GLES2VERTEXATTRIB3FPROC, glVertexAttrib3f);
	LOAD_AND_TEST_FUNCPTR(GLES2VERTEXATTRIB4FPROC, glVertexAttrib4f);
	LOAD_AND_TEST_FUNCPTR(GLES2VERTEXATTRIB1FVPROC, glVertexAttrib1fv);
	LOAD_AND_TEST_FUNCPTR(GLES2VERTEXATTRIB2FVPROC, glVertexAttrib2fv);
	LOAD_AND_TEST_FUNCPTR(GLES2VERTEXATTRIB3FVPROC, glVertexAttrib3fv);
	LOAD_AND_TEST_FUNCPTR(GLES2VERTEXATTRIB4FVPROC, glVertexAttrib4fv);
	LOAD_AND_TEST_FUNCPTR(GLES2VERTEXATTRIBPOINTERPROC, glVertexAttribPointer);
	//glViewport; // defined in gl.h

	return true;
}
