#include "Plane.h"


Plane::Plane()
{
	//Default to x direction
	m_normal = Vector(1, 0, 0);

	m_distance = 0;

	m_colour = Colour(0.5, 0.5, 0.5, 0);
}

Plane::Plane(Vector normalValue, double distanceValue, Colour colourValue)
{
	m_normal = normalValue;
	m_distance = distanceValue;
	m_colour = colourValue;
}

Vector Plane::getNormalAt(Vector point)
{
	return m_normal;
}

double Plane::findIntersection(Ray ray)
{
	Vector rayDirection = ray.getRayDirection();

	double dotProdOfRay = rayDirection.DotProduct(m_normal);

	if (dotProdOfRay == 0)
	{
		// ray is parallel to plane
		return -1;
	}
	else
	{
		double b = m_normal.DotProduct(ray.getRayOrigin().AddVector(m_normal.MultiplyVector(m_distance).Negative()));
		return -1 * b / dotProdOfRay;
	}
}