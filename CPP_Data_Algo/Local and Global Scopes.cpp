#include "Cpp_Prime.h"

const int Cat = 1;

void Local_and_Global_Scopes()
{
	const int Cat = 2;
	std::cout << "Local and Global Scopes: " << Cat << std::endl; // 2
}

int dog = Cat; // dog == 1