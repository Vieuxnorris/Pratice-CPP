#include "Cpp_Prime.h"

void Static_Casting()
{
	double d1 = 3.2;
	double d2 = 3.9999;
	int i1 = static_cast<int>(d1); // i1 has value 3
	int i2 = static_cast<int>(d2); // i2 has value 3
	std::cout << "i1 = " << i1 << std::endl;
	std::cout << "i2 = " << i2 << std::endl;
}