#ifndef _COLOUR_H
#define _COLOUR_H

#include "math.h"

class Colour
{
public:
	Colour();

	Colour(double, double, double, double);

	// Methods
	double getColourRed() { return m_red; }
	double getColourGreen() { return m_green; }
	double getColourBlue() { return m_blue; }
	double getColourSpecial() { return m_special; }

	double setColourRed(double redValue) { m_red = redValue; }
	double setColourGreen(double greenValue) { m_green = greenValue; }
	double setColourBlue(double blueValue) { m_blue = blueValue; }
	double setColourSpecial(double specialValue) { m_special = specialValue; }

private:
	double m_red, m_green, m_blue, m_special;
};

#endif


