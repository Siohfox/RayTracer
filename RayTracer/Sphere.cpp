#include "Sphere.h"

Sphere::Sphere()
{
	m_centre = Vector(0, 0, 0);
	m_radius = 1;
	m_colour = Colour(0.5, 1, 0.5, 0);
}

Sphere::Sphere(Vector centreValue, double radiusValue, Colour colourValue)
{
	m_centre = centreValue;
	m_radius = radiusValue;
	m_colour = colourValue;
}