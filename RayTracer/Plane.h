#ifndef _PLANE_H
#define _PLANE_H

#include "math.h"
#include "Object.h"
#include "Vector.h"
#include "Colour.h"

class Plane : public Object
{
public:
	Plane();

	Plane(Vector, double, Colour);

	// Methods
	Vector getPlaneNormal() { return m_normal; }
	double getPlaneDistance() { return m_distance; }
	Colour getPlaneColour() { return m_colour; }

	Vector getNormalAt(Vector point);

	virtual double findIntesection(Ray ray);

private:
	Vector m_normal;
	double m_distance;
	Colour m_colour;
};

#endif
