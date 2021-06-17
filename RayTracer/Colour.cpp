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

Colour Colour::Clip()
{
	double allLight = m_red + m_green + m_blue;
	double excessLight = allLight - 3;
	if (excessLight > 0)
	{
		m_red = m_red + excessLight * (m_red / allLight);
		m_green = m_green + excessLight * (m_green / allLight);
		m_blue = m_blue + excessLight * (m_blue / allLight);
	}

	if (m_red > 1)
	{
		m_red = 1;
	}
	if (m_green > 1)
	{
		m_green = 1;
	}
	if (m_blue > 1)
	{
		m_blue = 1;
	}


	if (m_red < 0)
	{
		m_red = 0;
	}
	if (m_green < 0)
	{
		m_green = 0;
	}
	if (m_blue < 0)
	{
		m_blue = 0;
	}
	
	return Colour(m_red, m_green, m_blue, m_special);
}