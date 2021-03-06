#ifndef _SPHERE_H
#define _SPHERE_H

#include "math.h"
#include "Object.h"
#include "Vector.h"
#include "Colour.h"

class Sphere : public Object
{
public:
	Sphere();

	Sphere(Vector, double, Colour);

	// Methods
	Vector getSphereCentre() { return m_centre; }
	double getSphereRadius() { return m_radius; }
	virtual Colour getColour() { return m_colour; }

	virtual double findIntersection(Ray ray);

	virtual Vector getNormalAt(Vector point);

private:
	Vector m_centre;
	double m_radius;
	Colour m_colour;
};

#endif
