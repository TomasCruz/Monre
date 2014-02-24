#include "NativeApplication.h"
#include "NativeException.h"
#include "MatrixUtil.h"
#include "ContextUtil.h"
#include "ShaderUtil.h"

NativeApplication::NativeApplication() : gl(), aspectRatio(1.2f)
{
}

NativeApplication::~NativeApplication()
{
}

void NativeApplication::Initialize(float vertOffset, float rotStep)
{
	if (rotStep > 10.0f)
		throw NativeException("too big rotation step!");

	rotStep *= 2.0f * 3.14159265359f / 360.0f;
	AppInit(vertOffset, rotStep);
	GenerateVertexData();
}

void NativeApplication::DeinitGraphics()
{
	glDeleteProgram(theProgram);
	glDeleteBuffers(1, &vertexBufferObject);

	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(m_renderingContext);
	ReleaseDC(hwnd, m_deviceContext);
}

void NativeApplication::AddVertex0()		{ vertexData.push_back(-0.5f); vertexData.push_back(0.0f); vertexData.push_back(0.5f); vertexData.push_back(1.0f); }
void NativeApplication::AddVertex1()		{ vertexData.push_back(-0.5f); vertexData.push_back(0.0f); vertexData.push_back(-0.5f); vertexData.push_back(1.0f); }
void NativeApplication::AddVertex2()		{ vertexData.push_back(0.5f); vertexData.push_back(0.0f); vertexData.push_back(-0.5f); vertexData.push_back(1.0f); }
void NativeApplication::AddVertex3()		{ vertexData.push_back(0.5f); vertexData.push_back(0.0f); vertexData.push_back(0.5f); vertexData.push_back(1.0f); }
void NativeApplication::AddVertex4()		{ vertexData.push_back(0.0f); vertexData.push_back(1.0f); vertexData.push_back(0.0f); vertexData.push_back(1.0f); }

void NativeApplication::AddColor0()			{ vertexData.push_back(1.0f); vertexData.push_back(0.0f); vertexData.push_back(0.0f); vertexData.push_back(1.0f); }
void NativeApplication::AddColor1()			{ vertexData.push_back(0.0f); vertexData.push_back(1.0f); vertexData.push_back(0.0f); vertexData.push_back(1.0f); }
void NativeApplication::AddColor2()			{ vertexData.push_back(0.0f); vertexData.push_back(0.0f); vertexData.push_back(1.0f); vertexData.push_back(1.0f); }
void NativeApplication::AddColor3()			{ vertexData.push_back(1.0f); vertexData.push_back(1.0f); vertexData.push_back(0.0f); vertexData.push_back(1.0f); }
void NativeApplication::AddColor4()			{ vertexData.push_back(1.0f); vertexData.push_back(1.0f); vertexData.push_back(1.0f); vertexData.push_back(1.0f); }
void NativeApplication::AddColorBottom()	{ vertexData.push_back(0.77f); vertexData.push_back(0.75f); vertexData.push_back(0.65f); vertexData.push_back(1.0f); }

void NativeApplication::GenerateVertexData()
{
	AddVertex0(); AddVertex1(); AddVertex2(); AddVertex3(); AddVertex4(); AddVertex0(); AddVertex1(); AddVertex2(); AddVertex3();
	AddColor0(); AddColor1(); AddColor2(); AddColor3(); AddColor4(); AddColorBottom(); AddColorBottom(); AddColorBottom(); AddColorBottom();

	indexData.push_back(0); indexData.push_back(4); indexData.push_back(1); 
	indexData.push_back(1); indexData.push_back(4); indexData.push_back(2); 
	indexData.push_back(2); indexData.push_back(4); indexData.push_back(3); 
	indexData.push_back(3); indexData.push_back(4); indexData.push_back(0); 
	indexData.push_back(5); indexData.push_back(6); indexData.push_back(8); 
	indexData.push_back(8); indexData.push_back(6); indexData.push_back(7); 
}

void NativeApplication::OpenGLInit(HWND wnd, HDC deviceContext, HGLRC renderingContext)
{
	// GL thread class had loaded dummy context
	if (!gl.LoadOpenGLES2Functions())
		throw NativeException("OpenGLES2 function loading failed");

	hwnd = wnd;
	m_deviceContext = deviceContext;
	m_renderingContext = renderingContext;
	if (!ContextUtil::DestroyDummyAndCreateRealContext(gl, hwnd, &m_deviceContext, &m_renderingContext))
		throw NativeException("Destroying dummy and creating real context failed");

	std::vector<GLuint> shaderList;
	try
	{
		shaderList.push_back(ShaderUtil::LoadAndCompileShader(GL_VERTEX_SHADER, "..\\NativeApp\\shaders\\LocalTransform.vert"));
		shaderList.push_back(ShaderUtil::LoadAndCompileShader(GL_FRAGMENT_SHADER, "..\\NativeApp\\shaders\\StandardColors.frag"));
		theProgram = ShaderUtil::CreateProgram(shaderList);
	}
	catch(NativeException&) { throw; }

	offsetUniform = glGetUniformLocation(theProgram, "offset");
	modelMatrixUnif = glGetUniformLocation(theProgram, "modelMatrix");
	perspectiveMatrixUnif = glGetUniformLocation(theProgram, "perspectiveMatrix");

	CalculatePerspectiveMatrix();

	glUseProgram(theProgram);
	glUniformMatrix4fv(perspectiveMatrixUnif, 1, GL_FALSE, perspectiveMatrix);
	glUseProgram(0);

	InitializeVertexBuffer();

	// VAO is necessary when using core profile, unless code is run using NVidia card. At least, that's how I understood this obscure subject.
	// see https://www.opengl.org/discussion_boards/showthread.php/181092-Drawing-a-single-point-without-VAO-on-NVIDIA-and-AMD
	//gl.glGenVertexArrays(1, &vao);
	//gl.glBindVertexArray(vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
}

void NativeApplication::InitializeVertexBuffer()
{
	glGenBuffers(1, &vertexBufferObject);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertexData.size(), &vertexData[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &indexBufferObject);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLshort) * indexData.size(), &indexData[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void NativeApplication::CalculatePerspectiveMatrix()
{
	MatrixUtil::Frustum(perspectiveMatrix, -1.0, 1.0, -1.0, 1.0, 1.0, 7.0);
}

void NativeApplication::CalculateModelViewMatrix()
{
	MatrixUtil::RotateY(modelViewMatrix, currentRotation);
}

void NativeApplication::Render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(theProgram);

	CalculateModelViewMatrix();
	glUniformMatrix4fv(modelMatrixUnif, 1, GL_FALSE, modelViewMatrix);
	glUniform3f(offsetUniform, 0.0f, currentOffset, -1.8f);

	size_t colorData = sizeof(float) * vertexData.size() / 2;
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)colorData);

	glDrawElements(GL_TRIANGLES, (GLsizei)indexData.size(), GL_UNSIGNED_SHORT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glUseProgram(0);
}

void NativeApplication::Resize(int width, int height)
{
	windowWidth = width;
	windowHeight = height;

	int minX, maxX, minY, maxY;
	float neededHeight = windowWidth * aspectRatio;
	if (windowHeight < neededHeight)
	{
		int rWidth = (int)((float)(windowWidth * windowHeight) / neededHeight);
		minX = (windowWidth - rWidth) / 2;
		maxX = rWidth;
		minY = 0;
		maxY = windowHeight;
	}
	else
	{
		int rHeight = (int)neededHeight;
		minX = 0;
		maxX = windowWidth;
		minY = (windowHeight - rHeight) / 2;
		maxY = rHeight;
	}

	glViewport(minX, minY, (GLsizei)maxX, (GLsizei)maxY);
}

void NativeApplication::AppInit(float vertOffset, float rotStep)
{
	currentOffset = vertOffset;
	currentRotation = 0.0f;
	rotationStep = rotStep;
}

void NativeApplication::IncreaseOffset() { currentOffset += 0.01f; }
void NativeApplication::DecreaseOffset() { currentOffset -= 0.01f; }
void NativeApplication::IncreaseRotation() { currentRotation += rotationStep; }
void NativeApplication::DecreaseRotation() { currentRotation -= rotationStep; }
