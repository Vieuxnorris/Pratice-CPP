#include "Cpp_Prime.h"

void References() 
{
	std::string author = "Samuel Clemens";
	std::string& penName = author;
	penName = "Mark Twain";
	std::cout << author << std::endl;
}