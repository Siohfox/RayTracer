#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize >> 8);
	bmpfileheader[4] = (unsigned char)(filesize >> 16);
	bmpfileheader[5] = (unsigned char)(filesize >> 24);

	bmpinfoheader[4] = (unsigned char)(width);
	bmpinfoheader[5] = (unsigned char)(width >> 8);
	bmpinfoheader[6] = (unsigned char)(width >> 16);
	bmpinfoheader[7] = (unsigned char)(width >> 24);

	bmpinfoheader[8] = (unsigned char)(height);
	bmpinfoheader[9] = (unsigned char)(height >> 8);
	bmpinfoheader[10] = (unsigned char)(height >> 16);
	bmpinfoheader[11] = (unsigned char)(height >> 24);

	bmpinfoheader[21] = (unsigned char)(s);
	bmpinfoheader[22] = (unsigned char)(s >> 8);
	bmpinfoheader[23] = (unsigned char)(s >> 16);
	bmpinfoheader[24] = (unsigned char)(s >> 24);

	bmpinfoheader[25] = (unsigned char)(ppm);
	bmpinfoheader[26] = (unsigned char)(ppm >> 8);
	bmpinfoheader[27] = (unsigned char)(ppm >> 16);
	bmpinfoheader[28] = (unsigned char)(ppm >> 24);

	bmpinfoheader[29] = (unsigned char)(ppm);
	bmpinfoheader[30] = (unsigned char)(ppm >> 8);
	bmpinfoheader[31] = (unsigned char)(ppm >> 16);
	bmpinfoheader[32] = (unsigned char)(ppm >> 24);

	//file = fopen(filename, "wb");

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

int thisOne;

int main(int argc, char* argv[])
{
	std::cout << "rendering..." << std::endl;

	int dpi = 72;
	int width = 640;
	int height = 480;
	int totalNumberOfPixels = width * height;


	RGBType* pixels = new RGBType[totalNumberOfPixels];

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			thisOne = y * width + x;

			pixels[thisOne].red = 23;
			pixels[thisOne].green = 222;
			pixels[thisOne].blue = 10;

			//return colour
		}
	}

	SaveBMP("scene.bmp", width, height, dpi, pixels);

	return 0;
}