#include "Cpp_Prime.h"

void For_loop()
{
	const int NUM_ELEMENTS = 100;
	double b[NUM_ELEMENTS];
	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		if (b[i] > 0)
			std::cout << "First For Loop -> " << b[i] << std::endl;
		else
			b[i] = std::rand() % 100;
	}
	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		std::cout << "Second For Loop -> " << b[i] << std::endl;
	}
}