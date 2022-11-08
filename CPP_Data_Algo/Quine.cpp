#include "Object-Oriented_Design.h"
#include <fstream>


int Quine()
{
	std::string filename = "Quine.cpp";
	std::string line;

	std::ifstream inFile;
	inFile.open(filename.c_str());
	if (inFile.fail())
	{
		std::cout << "\nThe file was not successfully opened" << "\n Please check that the file currently exists." << std::endl;
		exit(1);
	}
	while (std::getline(inFile, line))
		std::cout << line << std::endl;
	inFile.close();
	return EXIT_SUCCESS;
}