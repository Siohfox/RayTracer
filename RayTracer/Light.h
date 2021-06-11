#ifndef _LIGHT_H
#define _LIGHT_H

#include "Vector.h"
#include "Colour.h"

class Light
{
public:
	Light();

	Light(Vector, Colour);

	// Methods
	Vector getLightPosition() { return m_position; }
	Colour getLightcolour() { return m_colour; }

private:
	Vector m_position;
	Colour m_colour;
};

#endif
