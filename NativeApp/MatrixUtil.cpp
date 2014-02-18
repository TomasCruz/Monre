#include "MatrixUtil.h"
#include <string>
#include <math.h>

MatrixUtil::MatrixUtil() {}
MatrixUtil::~MatrixUtil() {}

void MatrixUtil::Frustum(float* frustumArray, double left, double right, double bottom, double top, double nearPlane, double farPlane)
{
	memset(frustumArray, 0, sizeof(float) * 16);

	frustumArray[0] = (float)(2.0 * nearPlane / (right - left));
	frustumArray[5] = (float)(2.0 * nearPlane / (top - bottom));
	frustumArray[8] = (float)((right + left) / (right - left));
	frustumArray[9] = (float)((top + bottom) / (top - bottom));
	frustumArray[10] = (float)(-(farPlane + nearPlane) / (farPlane - nearPlane));
	frustumArray[14] = (float)(-2.0 * farPlane * nearPlane / (farPlane - nearPlane));
	frustumArray[11] = -1.0f;
}

void MatrixUtil::RotateY(float* matrix, float angleRad)
{
	memset(matrix, 0, sizeof(float) * 16);

	float fCos = cosf(angleRad);
	float fSin = sinf(angleRad);

	// y axis rotation
	matrix[0] = matrix[10] = fCos;
	matrix[5] = matrix[15] = 1.0f;
	matrix[2] = -fSin;
	matrix[8] = fSin;
}
