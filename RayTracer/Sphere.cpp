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
	Vector ray_origin = ray.getRayOrigin();
	double ray_origin_x = ray_origin.getVectorX();
	double ray_origin_y = ray_origin.getVectorY();
	double ray_origin_z = ray_origin.getVectorZ();

	Vector ray_direction = ray.getRayDirection();
	double ray_direction_x = ray_direction.getVectorX();
	double ray_direction_y = ray_direction.getVectorY();
	double ray_direction_z = ray_direction.getVectorZ();

	Vector sphere_center = m_centre;
	double sphere_center_x = sphere_center.getVectorX();
	double sphere_center_y = sphere_center.getVectorY();
	double sphere_center_z = sphere_center.getVectorZ();

	double a = 1; // normalized
	double b = (2 * (ray_origin_x - sphere_center_x) * ray_direction_x) + (2 * (ray_origin_y - sphere_center_y) * ray_direction_y) + (2 * (ray_origin_z - sphere_center_z) * ray_direction_z);
	double c = pow(ray_origin_x - sphere_center_x, 2) + pow(ray_origin_y - sphere_center_y, 2) + pow(ray_origin_z - sphere_center_z, 2) - (m_radius * m_radius);


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