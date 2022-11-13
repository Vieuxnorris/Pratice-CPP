#include "Object-Oriented_Design.h"

class ReadWorld {
public:
	ReadWorld(std::string words);
private:
	std::string list;
	std::string arr[100], word = "", temp;
	int exist[100] = { 0 };
	const char blank = ' ';
};

ReadWorld::ReadWorld(std::string words) : list(words)
{
	int j = 0;

	for (int i = 0; i < list.length(); i++)
	{
		if (this->list[i] == this->blank)
		{
			this->arr[j] = this->word;
			this->word = "";
			j++;
		}
		else
		{
			this->word += this->list[i];
		}
	}
	this->arr[j] = this->word;

	for (int i = 0; i <= j; i++)
	{
		temp = arr[i];
		for (int k = i; k <= j; k++)
		{
			if (this->arr[k] == temp && i != k)
			{
				this->exist[k] = 1;
			}
		}
	}

	for (int i = 0; i <= j; i++)
	{
		while (this->exist[i] == 1 && i <= j)
		{
			i++;
		}
		temp = this->arr[i];
		int count = 0;
		for (int k = 0; k <= j; k++)
		{
			if (temp == arr[k])
				count++;
		}
		std::fflush(stdin);
		std::cout << temp << " appears " << count << " times. " << std::endl;
	}
}

int FrequencyWords()
{ 
	ReadWorld readworld("count the number of words as the number of words in the line");
	return EXIT_SUCCESS;
}
