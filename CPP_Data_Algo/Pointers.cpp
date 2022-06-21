#include "Cpp_Prime.h"

void Pointers()
{
	enum mealPref { REGULAR, VEGAN, GLUTEN_FREE, DIETARY };

	struct Passenger {
		std::string name;
		mealPref meal;
		bool isFreqFlyer;
		std::string freqFlyerNo;
	};
	

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

	Passenger* pass;

	pass = new Passenger;
	pass->name = "John"; // (*pass).name is equivalent to pass->name
	pass->meal = VEGAN;
	pass->isFreqFlyer = true;
	pass->freqFlyerNo = "12345";
	
	std::cout << pass->name << std::endl;
	delete pass;

	char* buffer = new char[500];
	buffer[3] = 'a';
	std::cout << buffer[3] << std::endl;
	delete[] buffer;
}