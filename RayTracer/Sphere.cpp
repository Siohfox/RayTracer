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

double Sphere::findIntersection(Ray ray)
{
	Vector rayOrigin = ray.getRayOrigin();
	double rayOriginX = rayOrigin.getVectorX();
	double rayOriginY = rayOrigin.getVectorY();
	double rayOriginZ = rayOrigin.getVectorZ();

	Vector rayDirection = ray.getRayOrigin();
	double rayDirectionX = rayDirection.getVectorX();
	double rayDirectionY = rayDirection.getVectorY();
	double rayDirectionZ = rayDirection.getVectorZ();

	Vector sphereCentre = m_centre;
	double sphereCentreX = sphereCentre.getVectorX();
	double sphereCentreY = sphereCentre.getVectorY();
	double sphereCentreZ = sphereCentre.getVectorZ();

	double a = 1; // normalized
	double b = (2 * (rayOriginX - sphereCentreX) * rayDirectionX) + (2 * (rayOriginY - sphereCentreY) * rayDirectionY) + (2 * (rayOriginZ - sphereCentreZ) * rayDirectionZ);
	double c = pow(rayOriginX - sphereCentreX, 2) + pow(rayOriginY - sphereCentreY, 2) + pow(rayOriginZ - sphereCentreZ, 2) - (m_radius*m_radius);

	double discriminant = b * b - 4 * c;

	if (discriminant > 0)
	{
		// The ray intersects the sphere
		// But the ray can intersect on two sides of the sphere

		// The first root
		double rootOne = ((-1 * b - sqrt(discriminant)) / 2) - 0.000001;

		if (rootOne > 0)
		{
			// the first root is the smallest positive root
			return rootOne;
		}
		else
		{
			// The second root is the smallest positive root
			double rootTwo = ((sqrt(discriminant) - b) / 2) - 0.000001;
			return rootTwo;
		}
	}

	else
	{
		// the ray missed the sphere
		return -1;
	}
}

Vector Sphere::getNormalAt(Vector point)
{
	// normal always points away from the center of a sphere
	Vector normalVector = point.AddVector(m_centre.Negative()).Normalize();
	return normalVector;
}