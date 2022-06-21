#include "Cpp_Prime.h"

namespace myglobals {
	int cat2 = 1;
	std::string dog = "bow wow";
}

using std::string; // make just std::string available
using namespace myglobals; // makes all of myglobals available

void Namespace()
{
	int cat = 2;
	std::cout << "cat = " << cat << std::endl;
	std::cout << "myglobals::cat = " << cat2 << std::endl;
}