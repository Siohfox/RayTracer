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
	Colour getObjectColour() { return Colour (0.0, 0.0, 0.0, 0); }

	virtual double findIntersection(Ray ray);

};

#endif
