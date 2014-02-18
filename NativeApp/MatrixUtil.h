#ifndef _MatrixUtil_h_
#define _MatrixUtil_h_

class MatrixUtil
{
public:
	MatrixUtil();
	~MatrixUtil();

	static void Frustum(float* frustumArray, double left, double right, double bottom, double top, double nearPlane, double farPlane);
	static void RotateY(float* matrix, float angleRad);
};
#endif
