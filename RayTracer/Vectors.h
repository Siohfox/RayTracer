#ifndef _VECTORS_H
#define _VECTORS_H

class Vectors
{
public:
	Vectors();

	Vectors(double, double, double);

	// Methods
	double getVectorX() { return x; }
	double getVectorY() { return y; }
	double getVectorZ() { return z; }

private:
	double x, y, z;
};

#endif // !1


