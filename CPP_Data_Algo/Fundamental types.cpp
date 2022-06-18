#include "Cpp_Prime.h"

void Fundamental_types()
{
	short n;
	int octalnumber = 0400; // octal number of 400, 400(base 8) = 256 (base 10)
	char newline_character = '\n';
	long BIGnumber = 314159265L; // long is a 64-bit integer
	short _aSTRANGE__1234_variABIE_NaMe;
	
	enum Day { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
	enum Month { January, February, March, April, May, June, July, August, September, October, November, December };
	Day today = Monday;
	Month thisMonth = January;
	std::cout << "Today is " << today << " and I am " << thisMonth << std::endl;
}