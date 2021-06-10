#include "Vector.h"

// Default Vector Constructor
Vector::Vector()
{
	// Defaults
	m_x = 0;
	m_y = 0;
	m_z = 0;
}

// Vector constructor with params
Vector::Vector(double _x, double _y, double _z)
{
	m_x = _x;
	m_y = _y;
	m_z = _z;
}