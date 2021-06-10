#include "Ray.h"

Ray::Ray()
{
	m_origin = Vector(0, 0, 0);
	m_direction = Vector(1, 0, 0);
}

Ray::Ray(Vector _origin, Vector _direction)
{
	m_origin = _origin;
	m_direction = _direction;
}