#ifndef _ShaderUtil_h_
#define _ShaderUtil_h_

#include "LoadUtil.h"
#include <string>
#include <vector>

class ShaderUtil
{
public:
	ShaderUtil();
	~ShaderUtil();

	static GLuint LoadAndCompileShader(GLenum eShaderType, const std::string &shaderFilePath);
	static GLuint CreateProgram(const std::vector<GLuint> &shaderList);
	static GLuint LinkProgram(const std::vector<GLuint> &shaders);
	static void ThrowIfShaderCompileFailed(GLuint shader);
	static void ThrowIfProgramLinkFailed(GLuint program);
};
#endif
