#include "Cpp_Prime.h"

void Traditional_c_style_casting()
{
	int cat = 14;
	double dog = (double)cat; // traditional C_style cast
	double pig = double(cat); // C++ functional cast

	int i1 = 18;
	int i2 = 16;
	double dv1 = i1 / i2; // dv1 has value 1.0
	double dv2 = double(i1) / double(i2);
	double dv3 = double(i1 / i2);
}