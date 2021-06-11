#include "Colour.h"


Colour::Colour()
{
	m_red = 0.5;
	m_green = 0.5;
	m_blue = 0.5;
	m_special = 0.5;
}

Colour::Colour(double red, double green, double blue, double special)
{
	m_red = red;
	m_green = green;
	m_blue = blue;
	m_special = special;
}