#ifndef _NativeApplication_h_
#define _NativeApplication_h_

#include "LoadUtil.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <exception>
#include <stdexcept>

class NativeApplication
{
public:
	NativeApplication();
	~NativeApplication();

	void Initialize(float vertOffset, float rotStep);
	void Render();
	void Resize(int width, int height);
	void OpenGLInit(HWND wnd, HDC deviceContext, HGLRC renderingContext);
	void DeinitGraphics();

	void IncreaseOffset();
	void DecreaseOffset();
	void IncreaseRotation();
	void DecreaseRotation();

private:
	HWND hwnd;
	HDC m_deviceContext;
	HGLRC m_renderingContext;
	LoadUtil gl;

	GLuint theProgram;
	GLuint offsetUniform;
	GLuint modelMatrixUnif;
	GLuint perspectiveMatrixUnif;
	GLuint vertexBufferObject, indexBufferObject;
	GLuint vao;

	int windowWidth, windowHeight;
	float aspectRatio;
	float currentOffset, currentRotation, rotationStep;
	float perspectiveMatrix[16];
	float modelViewMatrix[16];
	std::vector<float> vertexData;
	std::vector<GLshort> indexData;

	// methods
	void AppInit(float vertOffset, float rotStep);
	void AddVertex0();
	void AddVertex1();
	void AddVertex2();
	void AddVertex3();
	void AddVertex4();
	void AddColor0();
	void AddColor1();
	void AddColor2();
	void AddColor3();
	void AddColor4();
	void AddColorBottom();
	void GenerateVertexData();

	void CalculatePerspectiveMatrix();
	void CalculateModelViewMatrix();
	void InitializeVertexBuffer();
};
#endif
