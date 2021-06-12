#ifndef _LIGHT_H
#define _LIGHT_H

#include "Source.h"
#include "Vector.h"
#include "Colour.h"


class Light : public Source
{
public:
	Light();

	Light(Vector, Colour);

	// Methods
	Vector getLightPosition() { return m_position; }
	Colour getColour() { return m_colour; }

private:
	Vector m_position;
	Colour m_colour;
};

#endif
