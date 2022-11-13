#include "Object-Oriented_Design.h"
#include <fstream>

class Read {
public:
	Read(std::string document);
private:
	std::string document;
	char alphabets[27] = { ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	int frequency[27] = { 0 };
};

Read::Read(std::string document)
{
	std::string line;

	std::ifstream inFile;
	inFile.open(document.c_str());
	if (inFile.fail())
	{
		std::cout << "\n The file was not successfully opened" << "\n Please check that the file currently exists" << std::endl;
		exit(1);
	}
	while (getline(inFile, line))
	{
		for (int i = 0; i < line.length(); i++)
		{
			char temp = line[i];
			for (int j = 1; j < 27; j++)
			{
				if (temp == this->alphabets[j])
					this->frequency[j]++;
			}
		}
	}
	inFile.close();

	for (int j = 1; j < 27; j++)
	{
		if (this->frequency[j])
		{
			std::cout << alphabets[j] << " ";
			for (int k = 1; k <= this->frequency[j]; k++)
			{
				std::cout << '#';
			}
			std::cout << std::endl;
		}
	}
}

int FrequencyAlpha()
{
	Read documentread("document.dat");
	return EXIT_SUCCESS;
}