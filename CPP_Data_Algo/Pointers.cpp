#include "Cpp_Prime.h"

void Pointers()
{
	char ch = 'Q'; // char is a single byte
	char* p = &ch; // p is a pointer to char
	std::cout << *p; // *p is the value of ch
	ch = 'Z'; // ch is now 'Z'
	std::cout << *p; // *p is still 'Z'
	*p = 'X'; // *p is now 'X'
	std::cout << *p; // *p is now 'X'
	int* x, y, z;
	y = 20;
	z = 30;
	x = &y; // x is a pointer to int
	*x = 60; // x is now 60
	std::cout << *x << std::endl; // *x is 60 and y is 60
}