#include "Camera.h"

Camera::Camera()
{
	m_camPosition = Vector(0, 0, 0);
	m_camDirection = Vector(0, 0, 1);
	m_camRight = Vector(0, 0, 0);
	m_camDown = Vector(0, 0, 0);
}

Camera::Camera(Vector _position, Vector _direction, Vector _right, Vector _down)
{
	m_camPosition = _position;
	m_camDirection = _direction;
	m_camRight = _right;
	m_camDown = _down;
}