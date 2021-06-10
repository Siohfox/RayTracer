#ifndef _RAY_H
#define _RAY_H

#include "Vector.h"

class Ray
{
public:
	Ray();

	Ray(Vector, Vector);

	// Methods
	Vector getRayOrigin() { return m_origin; }
	Vector getRayDirection() { return m_direction; }

private:
	Vector m_origin, m_direction;
};

#endif


