#include "ShaderUtil.h"
#include "NativeException.h"
#include <fstream>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <algorithm>

ShaderUtil::ShaderUtil() {}
ShaderUtil::~ShaderUtil() {}

GLuint ShaderUtil::LoadAndCompileShader(GLenum eShaderType, const std::string &shaderFilePath)
{
	std::string filename = shaderFilePath;
	std::ifstream shaderFile(filename.c_str());
	std::stringstream shaderData;
	shaderData << shaderFile.rdbuf();
	shaderFile.close();
	std::string shaderText = shaderData.str();

	try
	{
		GLuint shader = glCreateShader(eShaderType);
		GLint textLength = (GLint)shaderText.size();
		const char *pText = static_cast<const char *>(shaderText.c_str());
		glShaderSource(shader, 1, &pText, &textLength);
		glCompileShader(shader);

		ThrowIfShaderCompileFailed(shader);

		return shader;
	}
	catch(NativeException&) { throw; }
	catch(std::exception &e) { throw NativeException(const_cast<char*>(e.what())); }

	return 0;
}

GLuint ShaderUtil::CreateProgram(const std::vector<GLuint> &shaderList)
{
	try
	{
		GLuint prog = LinkProgram(shaderList);
		std::for_each(shaderList.begin(), shaderList.end(), glDeleteShader);
		return prog;
	}
	catch(NativeException&) { throw; }
	catch(std::exception &e)
	{
		std::for_each(shaderList.begin(), shaderList.end(), glDeleteShader);
		fprintf(stderr, "%s\n", e.what());
		throw;
	}
}

GLuint ShaderUtil::LinkProgram(const std::vector<GLuint> &shaders)
{
	GLuint program = glCreateProgram();

	for(size_t loop = 0; loop < shaders.size(); ++loop)
		glAttachShader(program, shaders[loop]);

	glLinkProgram(program);
	ThrowIfProgramLinkFailed(program);

	for(size_t loop = 0; loop < shaders.size(); ++loop)
		glDetachShader(program, shaders[loop]);

	return program;
}

void ShaderUtil::ThrowIfShaderCompileFailed(GLuint shader)
{
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
		throw NativeException("shader compile failed");
}

void ShaderUtil::ThrowIfProgramLinkFailed(GLuint program)
{
	GLint status;
	glGetProgramiv (program, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
		throw NativeException("program link failed");
}
