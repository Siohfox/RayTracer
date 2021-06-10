#ifndef _CAMERA_H
#define _CAMERA_H

#include "Vector.h"

class Camera
{
public:
	Camera();

	Camera(Vector, Vector, Vector, Vector);

	// Methods
	Vector getCameraPosition() { return m_camPosition; }
	Vector getCameraDirection() { return m_camDirection; }
	Vector getCameraRight() { return m_camRight; }
	Vector getCameraDown() { return m_camDown; }

private:
	Vector m_camPosition, m_camDirection, m_camRight, m_camDown;
};

#endif