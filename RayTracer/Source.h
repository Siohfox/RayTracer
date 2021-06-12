#ifndef _SOURCE_H
#define _SOURCE_H

#include "Vector.h"
#include "Colour.h"

class Source
{
public:

	Source() {}

	virtual Vector getLightPosition() { return Vector(0, 0, 0); }
	virtual Colour getColour() { return Colour(1, 1, 1, 0); }

};

#endif // !_SOURCE_H



