#include "Cpp_Prime.h"

void Implicit_Casting()
{
	int i = 3;
	double d = 4.8;
	double d3 = i / d; // d3 = 0.625 = double(i) / d
	int i3 = d3; // i3 = 0 = int(d3)
				// Warning ! Assignment may lose information
}