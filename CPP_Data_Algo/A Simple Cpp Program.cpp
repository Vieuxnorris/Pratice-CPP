#include "Cpp_Prime.h"

// This program inputs two numbers x and y and outputs their sum
void A_Simple_Cpp_Program()
{
	int x, y;
	std::cout << "Please enter two numbers: ";
	std::cin >> x >> y; // Input x and y
	int sum = x + y; // Calculate the sum
	std::cout << "their sum is " << sum << std::endl;
}