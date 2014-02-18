#version 330

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;

smooth out vec4 theColor;

uniform vec3 offset;
uniform mat4 modelMatrix;
uniform mat4 perspectiveMatrix;

void main()
{
	vec4 cameraPos = position;
	cameraPos = modelMatrix * cameraPos;
	cameraPos = cameraPos + vec4(offset.x, offset.y, offset.z, 0.0);
	cameraPos = perspectiveMatrix * cameraPos;
	gl_Position = cameraPos;
	theColor = color;
}
