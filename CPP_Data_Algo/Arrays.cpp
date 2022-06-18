#include "Cpp_Prime.h"

void Arrays(void)
{
	double f[5]; // array of 5 doubles
	int m[10];
	f[4] = 2.5;
	m[2] = 4;
	std::cout << f[m[2]];

	int a[] = { 10,11,12,13 };
	bool b[] = { true,false};
	char c[] = { 'a','b','c','d' };

	char* p = c;
	char* q = &c[0];
	std::cout << *(p+1) << *q;
}