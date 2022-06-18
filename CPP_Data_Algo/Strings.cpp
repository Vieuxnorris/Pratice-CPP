#include "Cpp_Prime.h"

using std::string;

void Strings(void)
{
	string s = "to be";
	string t = "not " + s;
	string u = s + " or " + t;
	if (s > t)
		std::cout << u << std::endl;

	s = "John";
	int i = s.size();
	char c = s[3];
	s += " Smith";
	std::cout << s << std::endl;
}