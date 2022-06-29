#include "Cpp_Prime.h"

void if_Statement()
{
	int a = 10;
	int b = 20;
	if (a > b)
	{
		std::cout << "a is greater than b" << std::endl;
	}
	else if (a == b)
	{
		std::cout << "a is equal to b" << std::endl;
	}
	else
	{
		std::cout << "a is less than b" << std::endl;
	}
	
	char command;
	std::cin >> command;
	switch (command) {
		case 'a':							// if (command == 'a')
			std::cout << "a" << std::endl;
			break;
		case 'b':							// else if (command == 'b')
			std::cout << "a" << std::endl;
			break;
		default:							// else
			std::cout << "Unrecognized command\n" << std::endl;
			break;
	}
}