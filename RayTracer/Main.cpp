#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "Vector.h"
#include "Ray.h"
#include "Camera.h"
#include "Colour.h"
#include "Light.h"
#include "Sphere.h"
#include "Object.h"
#include "Plane.h"

struct RGBType
{
	double red;
	double green;
	double blue;
};

void SaveBMP(const char* filename, int width, int height, int dpi, RGBType* data)
{
	FILE* file;
	int k = width * height;
	int s = 4 * k;
	int filesize = 54 + s;

	double factor = 39.375;
	int m = static_cast<int>(factor);

	int ppm = dpi * m;

	unsigned char bmpfileheader[14] = { 'B', 'M', 0,0,0,0, 0,0,0,0, 54,0,0,0 };
	unsigned char bmpinfoheader[40] = { 40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0 };

	for (int x = 2, y = NULL; x < 6; x++, y+=8)
	{
		bmpfileheader[x] = (unsigned char)(filesize >> y);
	}
		

	//bmpfileheader[2] = (unsigned char)(filesize);
	//bmpfileheader[3] = (unsigned char)(filesize >> 8);
	//bmpfileheader[4] = (unsigned char)(filesize >> 16);
	//bmpfileheader[5] = (unsigned char)(filesize >> 24);


	for (int x = 4, y = NULL; x < 8; x++, y += 8)
	{
		bmpinfoheader[x] = (unsigned char)(width >> y);
	}

	//bmpinfoheader[4] = (unsigned char)(width);
	//bmpinfoheader[5] = (unsigned char)(width >> 8);
	//bmpinfoheader[6] = (unsigned char)(width >> 16);
	//bmpinfoheader[7] = (unsigned char)(width >> 24);

	for (int x = 8, y = NULL; x < 12; x++, y += 8)
	{
		bmpinfoheader[x] = (unsigned char)(height >> y);
	}

	//bmpinfoheader[8] = (unsigned char)(height);
	//bmpinfoheader[9] = (unsigned char)(height >> 8);
	//bmpinfoheader[10] = (unsigned char)(height >> 16);
	//bmpinfoheader[11] = (unsigned char)(height >> 24);

	for (int x = 21, y = NULL; x < 25; x++, y += 8)
	{
		bmpinfoheader[x] = (unsigned char)(s >> y);
	}

	//bmpinfoheader[21] = (unsigned char)(s);
	//bmpinfoheader[22] = (unsigned char)(s >> 8);
	//bmpinfoheader[23] = (unsigned char)(s >> 16);
	//bmpinfoheader[24] = (unsigned char)(s >> 24);

	for (int x = 25, y = NULL; x < 29; x++, y += 8)
	{
		bmpinfoheader[x] = (unsigned char)(ppm >> y);
	}

	//bmpinfoheader[25] = (unsigned char)(ppm);
	//bmpinfoheader[26] = (unsigned char)(ppm >> 8);
	//bmpinfoheader[27] = (unsigned char)(ppm >> 16);
	//bmpinfoheader[28] = (unsigned char)(ppm >> 24);

	for (int x = 29, y = NULL; x < 33; x++, y += 8)
	{
		bmpinfoheader[x] = (unsigned char)(ppm >> y);
	}

	//bmpinfoheader[29] = (unsigned char)(ppm);
	//bmpinfoheader[30] = (unsigned char)(ppm >> 8);
	//bmpinfoheader[31] = (unsigned char)(ppm >> 16);
	//bmpinfoheader[32] = (unsigned char)(ppm >> 24);

	#if _MSC_VER >= 1500
	errno_t error;
	error = fopen_s(&file, filename, "wb");
	if (error != 0) 
	{
		file = stdout;
	}
	#else
	stream = fopen(name, "w");
	if (stream == NULL) 
	{
		stream = stdout;
	}
	#endif

	fwrite(bmpfileheader, 1, 14, file);

	fwrite(bmpinfoheader, 1, 40, file);

	for (int i = 0; i < k; i++)
	{
		RGBType rgb = data[i];

		double red = (data[i].red) * 255;
		double green = (data[i].green) * 255;
		double blue = (data[i].blue) * 255;

		unsigned char colour[3] = { (int)floor(blue),(int)floor(green),(int)floor(red) };

		fwrite(colour, 1, 3, file);
	}

	fclose(file);
}

int winningObjectIndex(std::vector<double> objectIntersections)
{
	//return the index of the winning intersection
	int indexOfMinValue;

	// prevent unnecessary calculations
	if (objectIntersections.size() == 0)
	{
		// if there are no intersections
		return -1;
	}
	
	else if (objectIntersections.size() == 1)
	{
		if (objectIntersections.at(0) > 0)
		{
			// if that intersection is greater than zero, then it's our index of min value
			// zero is the winning object index of the array ( first element )
			return 0;
		}
		else
		{
			// otherwise the only intersection value is negative, the ray missed everything
			return -1;
		}
	}

	// Otherwise there are more than one intersections with the ray
	else
	{
		// find maximum value in the vector
		double max = 0;

		for (int i = 0; i < objectIntersections.size(); i++)
		{
			if (max < objectIntersections.at(i))
			{
				max = objectIntersections.at(i);
			}
		}

		// then starting from the max value, find the minimum positive value
		if (max > 0)
		{
			// we only want positive intersections
			for (int index = 0; index < objectIntersections.size(); index++)
			{
				if (objectIntersections.at(index) > 0 && objectIntersections.at(index) <= max)
				{
					max = objectIntersections.at(index);
					indexOfMinValue = index;
				}
			}

			return indexOfMinValue;
		}
		else
		{
			// all intersections where negative
			return -1;
		}
	}
}



int thisOne;

int main(int argc, char* argv[])
{
	std::cout << "rendering..." << std::endl;

	int dpi = 72;
	int width = 640;
	int height = 480;
	double aspectratio = (double)width / (double)height;
	int totalNumberOfPixels = width * height;

	RGBType* pixels = new RGBType[totalNumberOfPixels];


	Vector origin(0, 0, 0);
	Vector X(1, 0, 0);
	Vector Y(0, 1, 0);
	Vector Z(0, 0, 1);

	// Camera set up
	Vector cameraPosition(3, 1.5, -4);

	Vector lookAt(0, 0, 0);

	Vector diffBetweenCamAndTarget(cameraPosition.getVectorX() - lookAt.getVectorX(), cameraPosition.getVectorY() - lookAt.getVectorY(), cameraPosition.getVectorZ() - lookAt.getVectorZ());
	Vector cameraDirection = diffBetweenCamAndTarget.Negative().Normalize();
	Vector cameraRight = Y.CrossProduct(cameraDirection).Normalize();
	Vector cameraDown = cameraRight.CrossProduct(cameraDirection);

	// Create scene camera
	Camera sceneCamera(cameraPosition, cameraDirection, cameraRight, cameraDown);

	// Colours set up
	Colour white_light(1.0, 1.0, 1.0, 0);
	Colour veryGreen(0.5, 1.0, 0.5, 0.3);
	Colour maroony(0.5, 0.25, 0.25, 0);
	Colour gray(0.5, 0.5, 0.5, 0);
	Colour black(0.0, 0.0, 0.0, 0.0);

	// Create scene light
	Vector lightPosition(-7, 10, -10);
	Light sceneLight(lightPosition, white_light);


	// Scene Object
	double sphereRadius = 1;
	Sphere sceneSphere(origin, sphereRadius, veryGreen);
	Plane scenePlane(Y, -1, maroony);

	std::vector<Object*> sceneObjects;
	sceneObjects.push_back(dynamic_cast<Object*>(&sceneSphere));
	sceneObjects.push_back(dynamic_cast<Object*>(&scenePlane));

	double xAmount, yAmount;

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			thisOne = y * width + x;

			// start with no anti-aliasing
			if (width > height)
			{
				// The image is wider than it is tall
				xAmount = ((x + 0.5) / width) * aspectratio - ( ( (width - height) / (double)height ) / 2 );
				yAmount = ((height - y) + 0.5) / height;
			}
			else if (height > width)
			{
				// The image is taller than it is wide
				xAmount = (x + 0.5) / width;
				yAmount = ( ( (height - y) + 0.5) / height) / aspectratio - ( ( (height - width) / (double)width ) / 2 );
			}
			else
			{
				// The image is square
				xAmount = (x + 0.5) / width;
				yAmount = ((height - y) + 0.5) / height;
			}

			Vector cameraRayOrigin = sceneCamera.getCameraPosition();
			Vector cameraRayDirection = cameraDirection.AddVector(cameraRight.MultiplyVector(xAmount - 0.5).AddVector(cameraDown.MultiplyVector(yAmount - 0.5))).Normalize();
			Ray cameraRay(cameraRayOrigin, cameraRayDirection);

			std::vector<double> intersections;

			// See if ray intersects for each object in the scene
			for (int index = 0; index < sceneObjects.size(); index++)
			{
				// Find intersection with the cam ray and push it into the intersections vector
				intersections.push_back(sceneObjects.at(index)->findIntersection(cameraRay));
			}

			// Find which object is closer to the camera
			int indexOfWinningObject = winningObjectIndex(intersections);

			std::cout << indexOfWinningObject;

			if ((x > 200 && x < 440) && (y > 200 && y < 280))
			{
				pixels[thisOne].red = 23;
				pixels[thisOne].green = 222;
				pixels[thisOne].blue = 10;
			}
			else 
			{
				pixels[thisOne].red = 0;
				pixels[thisOne].green = 0;
				pixels[thisOne].blue = 0;
			}

			//return colour
		}
	}

	SaveBMP("scene.bmp", width, height, dpi, pixels);

	return 0;
}