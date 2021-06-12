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

// Find magnitude of a vector
double Vector::Magnitude()
{
	return sqrt((m_x* m_x) + (m_y * m_y) + (m_z * m_z));
}

// Find magnitude and returned normalized vector
Vector Vector::Normalize()
{
	double magnitude = sqrt((m_x * m_x) + (m_y * m_y) + (m_z * m_z));

	return Vector(m_x / magnitude, m_y / magnitude, m_z / magnitude);
}

Vector Vector::Negative()
{
	return Vector(-m_x, -m_y, -m_z);
}

double Vector::DotProduct(Vector v)
{
	return m_x * v.getVectorX() + m_y * v.getVectorY() + m_z * v.getVectorZ();
}

Vector Vector::CrossProduct(Vector v)
{
	return Vector(m_y * v.getVectorZ() - m_z * v.getVectorY(), m_z * v.getVectorX() - m_x * v.getVectorZ(), m_x * v.getVectorY() - m_y * v.getVectorX());
}

Vector Vector::AddVector(Vector v)
{
	return Vector(m_x+v.getVectorX(), m_y + v.getVectorY(), m_z + v.getVectorZ());
}

Vector Vector::MultiplyVector(double scalar)
{
	return Vector(m_x*scalar, m_y*scalar, m_z*scalar);
}