#ifndef _VECTOR_H
#define _VECTOR_H

#include "math.h"

class Vector
{
public:
	Vector();

	Vector(double, double, double);

	// Methods
	double getVectorX() { return m_x; }
	double getVectorY() { return m_y; }
	double getVectorZ() { return m_z; }

	double Magnitude();
	Vector Normalize();
	Vector Negative();
	double DotProduct(Vector);
	Vector CrossProduct(Vector);
	Vector AddVector(Vector);
	Vector MultiplyVector(double scalar);

private:
	double m_x, m_y, m_z;
};

#endif


