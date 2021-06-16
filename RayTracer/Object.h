#ifndef _OBJECT_H
#define _OBJECT_H

#include "Ray.h"
#include "Vector.h"
#include "Colour.h"

class Object
{
public:

	Object();

	// Methods
	virtual Colour getColour() { return Colour (0.0, 0.0, 0.0, 0); }

	virtual Vector getNormalAt(Vector point) { return Vector(0, 0, 0); }

	virtual double findIntersection(Ray ray);

};

#endif
