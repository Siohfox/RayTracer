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

	double brightness() { return m_red + m_green + m_blue / 3; }

	Colour colourScalar(double scalar) { return Colour(m_red * scalar, m_green * scalar, m_blue * scalar, m_special); }

	Colour addColour(Colour colour) { return Colour(m_red + colour.getColourRed(), m_green + colour.getColourGreen(), m_blue + colour.getColourBlue(), m_special); }

	Colour multiplyColour(Colour colour) { return Colour(m_red*colour.getColourRed(), m_green*colour.getColourGreen(), m_blue*colour.getColourBlue(), m_special); }

	Colour colourAverage(Colour colour) { return Colour((m_red + colour.getColourRed()) / 2, (m_green + colour.getColourGreen()) / 2, (m_blue + colour.getColourBlue()) / 2, m_special); }

	Colour Clip();


private:
	double m_red, m_green, m_blue, m_special;
};

#endif


