#ifndef _LoadUtil_h_
#define _LoadUtil_h_

#include "FunctionPtrTypes.h"

class LoadUtil
{
public:
	LoadUtil();
	~LoadUtil();

	int inline TestPointer(const void *pTest);
	bool LoadOpenGLES2Functions();

	// wgl stuff
	PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;
	PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB;
	PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;

	// Vertex Array Object stuff
	PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
	PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
	PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
	PFNGLISVERTEXARRAYPROC glIsVertexArray;
};

// OpenGL ES 2.0 stuff
extern GLES2ACTIVETEXTUREPROC glActiveTexture;
extern GLES2ATTACHSHADERPROC glAttachShader;
extern GLES2BINDATTRIBLOCATIONPROC glBindAttribLocation;
extern GLES2BINDBUFFERPROC glBindBuffer;
extern GLES2BINDFRAMEBUFFERPROC glBindFramebuffer;
extern GLES2BINDRENDERBUFFERPROC glBindRenderbuffer;
//extern GLES2BINDTEXTUREPROC glBindTexture; // defined in gl.h
extern GLES2BLENDCOLORPROC glBlendColor;
extern GLES2BLENDEQUATIONPROC glBlendEquation;
extern GLES2BLENDEQUATIONSEPARATEPROC glBlendEquationSeparate;
//glBlendFunc // defined in gl.h
extern GLES2BLENDFUNCSEPARATEPROC glBlendFuncSeparate;
extern GLES2BUFFERDATAPROC glBufferData;
extern GLES2BUFFERSUBDATAPROC glBufferSubData;
extern GLES2CHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus;
//glClear // defined in gl.h
//glClearColor // defined in gl.h
extern GLES2CLEARDEPTHFPROC glClearDepthf;
//glClearStencil // defined in gl.h
//glColorMask // defined in gl.h
extern GLES2COMPILESHADERPROC glCompileShader;
extern GLES2COMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D;
extern GLES2COMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D;
//glCopyTexImage2D; // defined in gl.h
//glCopyTexSubImage2D; // defined in gl.h
extern GLES2CREATEPROGRAMPROC glCreateProgram;
extern GLES2CREATESHADERPROC glCreateShader;
//glCullFace; // defined in gl.h
extern GLES2DELETEBUFFERSPROC glDeleteBuffers;
extern GLES2DELETEFRAMEBUFFERSPROC glDeleteFramebuffers;
extern GLES2DELETEPROGRAMPROC glDeleteProgram;
extern GLES2DELETERENDERBUFFERSPROC glDeleteRenderbuffers;
extern GLES2DELETESHADERPROC glDeleteShader;
//glDeleteTextures; // defined in gl.h
//glDepthFunc; // defined in gl.h
//glDepthMask; // defined in gl.h
extern GLES2DEPTHRANGEFPROC glDepthRangef;
extern GLES2DETACHSHADERPROC glDetachShader;
//glDisable; // defined in gl.h
extern GLES2DISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
//glDrawArrays; // defined in gl.h
//glDrawElements; // defined in gl.h
//glEnable // defined in gl.h
extern GLES2ENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
//glFinish // defined in gl.h
//glFlush // defined in gl.h
extern GLES2FRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer;
extern GLES2FRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D;
//glFrontFace // defined in gl.h
extern GLES2GENBUFFERSPROC glGenBuffers;
extern GLES2GENFRAMEBUFFERSPROC glGenFramebuffers;
extern GLES2GENRENDERBUFFERSPROC glGenRenderbuffers;
//glGenTextures // defined in gl.h
extern GLES2GENERATEMIPMAPPROC glGenerateMipmap;
//glGetBooleanv; // defined in gl.h
//glGetFloatv; // defined in gl.h
//glGetIntegerv; // defined in gl.h
extern GLES2GETACTIVEATTRIBPROC glGetActiveAttrib;
extern GLES2GETACTIVEUNIFORMPROC glGetActiveUniform;
extern GLES2GETATTACHEDSHADERSPROC glGetAttachedShaders;
extern GLES2GETATTRIBLOCATIONPROC glGetAttribLocation;
extern GLES2GETBUFFERPARAMETERIVPROC glGetBufferParameteriv;
//glGetError; // defined in gl.h
extern GLES2GETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv;
extern GLES2GETPROGRAMINFOLOGPROC glGetProgramInfoLog;
extern GLES2GETPROGRAMIVPROC glGetProgramiv;
extern GLES2GETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv;
extern GLES2GETSHADERINFOLOGPROC glGetShaderInfoLog;
extern GLES2GETSHADERPRECISIONFORMATPROC glGetShaderPrecisionFormat;
extern GLES2GETSHADERSOURCEPROC glGetShaderSource;
extern GLES2GETSHADERIVPROC glGetShaderiv;
//glGetString; // defined in gl.h
//glGetTexParameterfv; // defined in gl.h
//glGetTexParameteriv; // defined in gl.h
extern GLES2GETUNIFORMFVPROC glGetUniformfv;
extern GLES2GETUNIFORMIVPROC glGetUniformiv;
extern GLES2GETUNIFORMLOCATIONPROC glGetUniformLocation;
extern GLES2GETVERTEXATTRIBFVPROC glGetVertexAttribfv;
extern GLES2GETVERTEXATTRIBIVPROC glGetVertexAttribiv;
extern GLES2GETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv;
//glHint; // defined in gl.h
extern GLES2ISBUFFERPROC glIsBuffer;
//glIsEnabled; // defined in gl.h
extern GLES2ISFRAMEBUFFERPROC glIsFramebuffer;
extern GLES2ISPROGRAMPROC glIsProgram;
extern GLES2ISRENDERBUFFERPROC glIsRenderbuffer;
extern GLES2ISSHADERPROC glIsShader;
//glIsTexture; // defined in gl.h
//glLineWidth; // defined in gl.h
extern GLES2LINKPROGRAMPROC glLinkProgram;
//glPixelStorei; // defined in gl.h
//glPolygonOffset; // defined in gl.h
//glReadPixels; // defined in gl.h
extern GLES2RELEASESHADERCOMPILERPROC glReleaseShaderCompiler;
extern GLES2RENDERBUFFERSTORAGEPROC glRenderbufferStorage;
extern GLES2SAMPLECOVERAGEPROC glSampleCoverage;
//glScissor; // defined in gl.h
extern GLES2SHADERBINARYPROC glShaderBinary;
extern GLES2SHADERSOURCEPROC glShaderSource;
//glStencilFunc; // defined in gl.h
extern GLES2STENCILFUNCSEPARATEPROC glStencilFuncSeparate;
//glStencilMask; // defined in gl.h
extern GLES2STENCILMASKSEPARATEPROC glStencilMaskSeparate;
//glStencilOp; // defined in gl.h
extern GLES2STENCILOPSEPARATEPROC glStencilOpSeparate;
//glTexImage2D; // defined in gl.h
//glTexParameterf; // defined in gl.h
//glTexParameterfv; // defined in gl.h
//glTexParameteri; // defined in gl.h
//glTexParameteriv; // defined in gl.h
//glTexSubImage2D; // defined in gl.h
extern GLES2UNIFORM1FPROC glUniform1f;
extern GLES2UNIFORM2FPROC glUniform2f;
extern GLES2UNIFORM3FPROC glUniform3f;
extern GLES2UNIFORM4FPROC glUniform4f;
extern GLES2UNIFORM1IPROC glUniform1i;
extern GLES2UNIFORM2IPROC glUniform2i;
extern GLES2UNIFORM3IPROC glUniform3i;
extern GLES2UNIFORM4IPROC glUniform4i;
extern GLES2UNIFORM1FVPROC glUniform1fv;
extern GLES2UNIFORM2FVPROC glUniform2fv;
extern GLES2UNIFORM3FVPROC glUniform3fv;
extern GLES2UNIFORM4FVPROC glUniform4fv;
extern GLES2UNIFORM1IVPROC glUniform1iv;
extern GLES2UNIFORM2IVPROC glUniform2iv;
extern GLES2UNIFORM3IVPROC glUniform3iv;
extern GLES2UNIFORM4IVPROC glUniform4iv;
extern GLES2UNIFORMMATRIX2FVPROC glUniformMatrix2fv;
extern GLES2UNIFORMMATRIX3FVPROC glUniformMatrix3fv;
extern GLES2UNIFORMMATRIX4FVPROC glUniformMatrix4fv;
extern GLES2USEPROGRAMPROC glUseProgram;
extern GLES2VALIDATEPROGRAMPROC glValidateProgram;
extern GLES2VERTEXATTRIB1FPROC glVertexAttrib1f;
extern GLES2VERTEXATTRIB2FPROC glVertexAttrib2f;
extern GLES2VERTEXATTRIB3FPROC glVertexAttrib3f;
extern GLES2VERTEXATTRIB4FPROC glVertexAttrib4f;
extern GLES2VERTEXATTRIB1FVPROC glVertexAttrib1fv;
extern GLES2VERTEXATTRIB2FVPROC glVertexAttrib2fv;
extern GLES2VERTEXATTRIB3FVPROC glVertexAttrib3fv;
extern GLES2VERTEXATTRIB4FVPROC glVertexAttrib4fv;
extern GLES2VERTEXATTRIBPOINTERPROC glVertexAttribPointer;
//glViewport; // defined in gl.h

#endif
