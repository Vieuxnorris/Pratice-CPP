#include "Cpp_Prime.h"

void Constants_and_Typedef()
{
	const double PI = 3.141592653589793;
	const int CUT_OFF[] = { 90, 80, 70, 60 };
	const int N_DAYS = 7;
	const int N_HOURS = 24 * N_DAYS; // using a constant expression
	int counter[N_HOURS]; // an array of 168 ints

	typedef char* Bufferptr; // type Bufferptr is a pointer to a char
	typedef double Coodinate; // type Coodinate is a double

	Bufferptr buffer; // buffer is a Bufferptr
	Coodinate x, y; // x and y are Coodinate
	
}