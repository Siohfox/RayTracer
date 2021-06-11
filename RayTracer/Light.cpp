#include "Light.h"

Light::Light()
{
	m_position = Vector(0, 0, 0);
	m_colour = Colour(1, 1, 1, 0);
}

Light::Light(Vector position, Colour colour)
{
	m_position = m_position;
	m_colour = colour;
}