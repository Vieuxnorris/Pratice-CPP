#include "Cpp_Prime.h"

void while_and_do_while_loops()
{
	int i = 0;
	while (i < 10)
	{
		std::cout << "while -> " << i << std::endl;
		i++;
	}
	do
	{
		std::cout << "do while -> " << i << std::endl;
		i++;
	} while (i < 10);
}