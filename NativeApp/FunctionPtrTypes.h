#ifndef _FunctionPtrTypes_h_
#define _FunctionPtrTypes_h_

#include <windows.h>
#include <GL/gl.h>

/////////////
// DEFINES //
/////////////
#define WGL_DRAW_TO_WINDOW_ARB         0x2001
#define WGL_ACCELERATION_ARB           0x2003
#define WGL_SWAP_METHOD_ARB            0x2007
#define WGL_SUPPORT_OPENGL_ARB         0x2010
#define WGL_DOUBLE_BUFFER_ARB          0x2011
#define WGL_PIXEL_TYPE_ARB             0x2013
#define WGL_COLOR_BITS_ARB             0x2014
#define WGL_DEPTH_BITS_ARB             0x2022
#define WGL_STENCIL_BITS_ARB           0x2023
#define WGL_FULL_ACCELERATION_ARB      0x2027
#define WGL_SWAP_EXCHANGE_ARB          0x2028
#define WGL_TYPE_RGBA_ARB              0x202B
#define WGL_CONTEXT_MAJOR_VERSION_ARB  0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB  0x2092
#define WGL_CONTEXT_PROFILE_MASK_ARB   0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB			0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB	0x00000002

#define GL_ARRAY_BUFFER                   0x8892
#define GL_STATIC_DRAW                    0x88E4
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_INFO_LOG_LENGTH                0x8B84
#define GL_TEXTURE0                       0x84C0
#define GL_BGRA                           0x80E1
#define GL_ELEMENT_ARRAY_BUFFER           0x8893

typedef ptrdiff_t GLintptr;
typedef ptrdiff_t GLsizeiptr;
typedef char GLchar;

// wgl stuff
typedef BOOL (WINAPI * PFNWGLCHOOSEPIXELFORMATARBPROC) (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
typedef HGLRC (WINAPI * PFNWGLCREATECONTEXTATTRIBSARBPROC) (HDC hDC, HGLRC hShareContext, const int *attribList);
typedef BOOL (WINAPI * PFNWGLSWAPINTERVALEXTPROC) (int interval);

// Vertex Array Object stuff
typedef void (APIENTRY * PFNGLBINDVERTEXARRAYPROC)(GLuint);
typedef void (APIENTRY * PFNGLDELETEVERTEXARRAYSPROC)(GLsizei, const GLuint *);
typedef void (APIENTRY * PFNGLGENVERTEXARRAYSPROC)(GLsizei, GLuint *);
typedef GLboolean (APIENTRY * PFNGLISVERTEXARRAYPROC)(GLuint);

// OpenGL ES 2.0 stuff
typedef void (APIENTRY * GLES2ACTIVETEXTUREPROC)(GLenum);
typedef void (APIENTRY * GLES2ATTACHSHADERPROC)(GLuint, GLuint);
typedef void (APIENTRY * GLES2BINDATTRIBLOCATIONPROC)(GLuint, GLuint, const char *);
typedef void (APIENTRY * GLES2BINDBUFFERPROC)(GLenum, GLuint);
typedef void (APIENTRY * GLES2BINDFRAMEBUFFERPROC)(GLenum, GLuint);
typedef void (APIENTRY * GLES2BINDRENDERBUFFERPROC)(GLenum, GLuint);
//typedef void (APIENTRY * GLES2BINDTEXTUREPROC)(GLenum, GLuint); // defined in gl.h
typedef void (APIENTRY * GLES2BLENDCOLORPROC)(GLclampf, GLclampf, GLclampf, GLclampf);
typedef void (APIENTRY * GLES2BLENDEQUATIONPROC)(GLenum);
typedef void (APIENTRY * GLES2BLENDEQUATIONSEPARATEPROC)(GLenum, GLenum);
//glBlendFunc // defined in gl.h
typedef void (APIENTRY * GLES2BLENDFUNCSEPARATEPROC)(GLenum, GLenum, GLenum, GLenum);
typedef void (APIENTRY * GLES2BUFFERDATAPROC)(GLenum, GLsizeiptr, const GLvoid *, GLenum);
typedef void (APIENTRY * GLES2BUFFERSUBDATAPROC)(GLenum, GLintptr, GLsizeiptr, const GLvoid *);
typedef GLenum (APIENTRY * GLES2CHECKFRAMEBUFFERSTATUSPROC)(GLenum);
//glClear // defined in gl.h
//glClearColor // defined in gl.h
typedef void (APIENTRY * GLES2CLEARDEPTHFPROC)(GLclampf );
//glClearStencil // defined in gl.h
//glColorMask // defined in gl.h
typedef void (APIENTRY * GLES2COMPILESHADERPROC)(GLuint);
typedef void (APIENTRY * GLES2COMPRESSEDTEXIMAGE2DPROC)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *);
typedef void (APIENTRY * GLES2COMPRESSEDTEXSUBIMAGE2DPROC)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
//glCopyTexImage2D; // defined in gl.h
//glCopyTexSubImage2D; // defined in gl.h
typedef GLuint (APIENTRY * GLES2CREATEPROGRAMPROC)();
typedef GLuint (APIENTRY * GLES2CREATESHADERPROC)(GLenum);
//glCullFace; // defined in gl.h
typedef void (APIENTRY * GLES2DELETEBUFFERSPROC)(GLsizei, const GLuint *);
typedef void (APIENTRY * GLES2DELETEFRAMEBUFFERSPROC)(GLsizei, const GLuint *);
typedef void (APIENTRY * GLES2DELETEPROGRAMPROC)(GLuint);
typedef void (APIENTRY * GLES2DELETERENDERBUFFERSPROC)(GLsizei, const GLuint *);
typedef void (APIENTRY * GLES2DELETESHADERPROC)(GLuint);
//glDeleteTextures; // defined in gl.h
//glDepthFunc; // defined in gl.h
//glDepthMask; // defined in gl.h
typedef void (APIENTRY * GLES2DEPTHRANGEFPROC)(GLclampf, GLclampf);
typedef void (APIENTRY * GLES2DETACHSHADERPROC)(GLuint, GLuint);
//glDisable; // defined in gl.h
typedef void (APIENTRY * GLES2DISABLEVERTEXATTRIBARRAYPROC)(GLuint);
//glDrawArrays; // defined in gl.h
//glDrawElements; // defined in gl.h
//glEnable // defined in gl.h
typedef void (APIENTRY * GLES2ENABLEVERTEXATTRIBARRAYPROC)(GLuint);
//glFinish // defined in gl.h
//glFlush // defined in gl.h
typedef void (APIENTRY * GLES2FRAMEBUFFERRENDERBUFFERPROC)(GLenum, GLenum, GLenum, GLuint);
typedef void (APIENTRY * GLES2FRAMEBUFFERTEXTURE2DPROC)(GLenum, GLenum, GLenum, GLuint, GLint);
//glFrontFace // defined in gl.h
typedef void (APIENTRY * GLES2GENBUFFERSPROC)(GLsizei, GLuint *);
typedef void (APIENTRY * GLES2GENFRAMEBUFFERSPROC)(GLsizei, GLuint *);
typedef void (APIENTRY * GLES2GENRENDERBUFFERSPROC)(GLsizei, GLuint *);
//glGenTextures // defined in gl.h
typedef void (APIENTRY * GLES2GENERATEMIPMAPPROC)(GLenum);
//glGetBooleanv; // defined in gl.h
//glGetFloatv; // defined in gl.h
//glGetIntegerv; // defined in gl.h
typedef void (APIENTRY * GLES2GETACTIVEATTRIBPROC)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *);
typedef void (APIENTRY * GLES2GETACTIVEUNIFORMPROC)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *);
typedef void (APIENTRY * GLES2GETATTACHEDSHADERSPROC)(GLuint, GLsizei, GLsizei *, GLuint *);
typedef GLint (APIENTRY * GLES2GETATTRIBLOCATIONPROC)(GLuint, const GLchar *);
typedef void (APIENTRY * GLES2GETBUFFERPARAMETERIVPROC)(GLenum, GLenum, GLint *);
//glGetError; // defined in gl.h
typedef void (APIENTRY * GLES2GETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum, GLenum, GLenum, GLint *);
typedef void (APIENTRY * GLES2GETPROGRAMINFOLOGPROC)(GLuint, GLsizei, GLsizei *, GLchar *);
typedef void (APIENTRY * GLES2GETPROGRAMIVPROC)(GLuint, GLenum, GLint *);
typedef void (APIENTRY * GLES2GETRENDERBUFFERPARAMETERIVPROC)(GLenum, GLenum, GLint *);
typedef void (APIENTRY * GLES2GETSHADERINFOLOGPROC)(GLuint, GLsizei, GLsizei *, GLchar *);
typedef void (APIENTRY * GLES2GETSHADERPRECISIONFORMATPROC)(GLenum, GLenum, GLint *, GLint *);
typedef void (APIENTRY * GLES2GETSHADERSOURCEPROC)(GLuint, GLsizei, GLsizei *, GLchar *);
typedef void (APIENTRY * GLES2GETSHADERIVPROC)(GLuint, GLenum, GLint *);
//glGetString; // defined in gl.h
//glGetTexParameterfv; // defined in gl.h
//glGetTexParameteriv; // defined in gl.h
typedef void (APIENTRY * GLES2GETUNIFORMFVPROC)(GLuint , GLint , GLfloat *);
typedef void (APIENTRY * GLES2GETUNIFORMIVPROC)(GLuint , GLint , GLint *);
typedef GLint (APIENTRY * GLES2GETUNIFORMLOCATIONPROC)(GLuint, const char *);
typedef void (APIENTRY * GLES2GETVERTEXATTRIBFVPROC)(GLuint, GLenum, GLfloat *);
typedef void (APIENTRY * GLES2GETVERTEXATTRIBIVPROC)(GLuint, GLenum, GLint *);
typedef void (APIENTRY * GLES2GETVERTEXATTRIBPOINTERVPROC)(GLuint, GLenum, GLvoid* *);
//glHint; // defined in gl.h
typedef GLboolean (APIENTRY * GLES2ISBUFFERPROC)(GLuint );
//glIsEnabled; // defined in gl.h
typedef GLboolean (APIENTRY * GLES2ISFRAMEBUFFERPROC)(GLuint);
typedef GLboolean (APIENTRY * GLES2ISPROGRAMPROC)(GLuint);
typedef GLboolean (APIENTRY * GLES2ISRENDERBUFFERPROC)(GLuint);
typedef GLboolean (APIENTRY * GLES2ISSHADERPROC)(GLuint);
//glIsTexture; // defined in gl.h
//glLineWidth; // defined in gl.h
typedef void (APIENTRY * GLES2LINKPROGRAMPROC)(GLuint);
//glPixelStorei; // defined in gl.h
//glPolygonOffset; // defined in gl.h
//glReadPixels; // defined in gl.h
typedef void (APIENTRY * GLES2RELEASESHADERCOMPILERPROC)();
typedef void (APIENTRY * GLES2RENDERBUFFERSTORAGEPROC)(GLenum, GLenum, GLsizei, GLsizei);
typedef void (APIENTRY * GLES2SAMPLECOVERAGEPROC)(GLclampf, GLboolean);
//glScissor; // defined in gl.h
typedef void (APIENTRY * GLES2SHADERBINARYPROC)(GLsizei , const GLuint *, GLenum , const GLvoid *, GLsizei );
typedef void (APIENTRY * GLES2SHADERSOURCEPROC)(GLuint, GLsizei, const char **, const GLint *);
//glStencilFunc; // defined in gl.h
typedef void (APIENTRY * GLES2STENCILFUNCSEPARATEPROC)(GLenum , GLenum , GLint , GLuint );
//glStencilMask; // defined in gl.h
typedef void (APIENTRY * GLES2STENCILMASKSEPARATEPROC)(GLenum , GLuint );
//glStencilOp; // defined in gl.h
typedef void (APIENTRY * GLES2STENCILOPSEPARATEPROC)(GLenum , GLenum , GLenum , GLenum );
//glTexImage2D; // defined in gl.h
//glTexParameterf; // defined in gl.h
//glTexParameterfv; // defined in gl.h
//glTexParameteri; // defined in gl.h
//glTexParameteriv; // defined in gl.h
//glTexSubImage2D; // defined in gl.h
typedef void (APIENTRY * GLES2UNIFORM1FPROC)(GLint , GLfloat );
typedef void (APIENTRY * GLES2UNIFORM2FPROC)(GLint , GLfloat , GLfloat );
typedef void (APIENTRY * GLES2UNIFORM3FPROC)(GLint , GLfloat , GLfloat , GLfloat );
typedef void (APIENTRY * GLES2UNIFORM4FPROC)(GLint , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (APIENTRY * GLES2UNIFORM1IPROC)(GLint , GLint );
typedef void (APIENTRY * GLES2UNIFORM2IPROC)(GLint , GLint , GLint );
typedef void (APIENTRY * GLES2UNIFORM3IPROC)(GLint , GLint , GLint , GLint );
typedef void (APIENTRY * GLES2UNIFORM4IPROC)(GLint , GLint , GLint , GLint , GLint );
typedef void (APIENTRY * GLES2UNIFORM1FVPROC)(GLint , GLsizei , const GLfloat *);
typedef void (APIENTRY * GLES2UNIFORM2FVPROC)(GLint , GLsizei , const GLfloat *);
typedef void (APIENTRY * GLES2UNIFORM3FVPROC)(GLint , GLsizei , const GLfloat *);
typedef void (APIENTRY * GLES2UNIFORM4FVPROC)(GLint , GLsizei , const GLfloat *);
typedef void (APIENTRY * GLES2UNIFORM1IVPROC)(GLint , GLsizei , const GLint *);
typedef void (APIENTRY * GLES2UNIFORM2IVPROC)(GLint , GLsizei , const GLint *);
typedef void (APIENTRY * GLES2UNIFORM3IVPROC)(GLint , GLsizei , const GLint *);
typedef void (APIENTRY * GLES2UNIFORM4IVPROC)(GLint , GLsizei , const GLint *);
typedef void (APIENTRY * GLES2UNIFORMMATRIX2FVPROC)(GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (APIENTRY * GLES2UNIFORMMATRIX3FVPROC)(GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (APIENTRY * GLES2UNIFORMMATRIX4FVPROC)(GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (APIENTRY * GLES2USEPROGRAMPROC)(GLuint);
typedef void (APIENTRY * GLES2VALIDATEPROGRAMPROC)(GLuint );
typedef void (APIENTRY * GLES2VERTEXATTRIB1FPROC)(GLuint , GLfloat );
typedef void (APIENTRY * GLES2VERTEXATTRIB2FPROC)(GLuint , GLfloat , GLfloat );
typedef void (APIENTRY * GLES2VERTEXATTRIB3FPROC)(GLuint , GLfloat , GLfloat , GLfloat );
typedef void (APIENTRY * GLES2VERTEXATTRIB4FPROC)(GLuint , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (APIENTRY * GLES2VERTEXATTRIB1FVPROC)(GLuint , const GLfloat *);
typedef void (APIENTRY * GLES2VERTEXATTRIB2FVPROC)(GLuint , const GLfloat *);
typedef void (APIENTRY * GLES2VERTEXATTRIB3FVPROC)(GLuint , const GLfloat *);
typedef void (APIENTRY * GLES2VERTEXATTRIB4FVPROC)(GLuint , const GLfloat *);
typedef void (APIENTRY * GLES2VERTEXATTRIBPOINTERPROC)(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid *);
//glViewport; // defined in gl.h

#endif
