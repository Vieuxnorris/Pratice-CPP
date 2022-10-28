#include "Cpp_Prime.h"

enum MealType { NO_PREF, REGULAR, LOW_FAT, VEGETARIAN };

inline int min(int x, int y) { return (x < y ? x : y); }

struct Passenger {
	std::string name;
	MealType mealPref;
	bool isFreqFlyer;
	std::string freqFlyerNo;
};

bool operator==(const Passenger& x, const Passenger& y)
{
	return x.name == y.name
		&& x.mealPref == y.mealPref
		&& x.isFreqFlyer == y.isFreqFlyer
		&& x.freqFlyerNo == y.freqFlyerNo;
}

std::ostream& operator<<(std::ostream& out, const Passenger& pass)
{
	out << pass.name << " " << pass.mealPref;
	if (pass.isFreqFlyer)
		out << " " << pass.freqFlyerNo << std::endl;
	return out;
}

void print(int x) // print an integer
{
	std::cout << x;
}

void print(const Passenger& pass) // print a Passenger
{
	std::cout << pass.name << pass.mealPref;
	if (pass.isFreqFlyer)
		std::cout << " " << pass.freqFlyerNo;
}

void Overloading_and_inlining(void)
{
	Passenger pass = { "John Smith", REGULAR, true, "12345" };
	Passenger passClone = { "John Smith", REGULAR, true, "12345" };
	
	print(10);
	print(pass);
	std::cout << std::endl;

	// operator overloading ==
	bool result = pass.name == passClone.name;
	std::cout << result << std::endl;

	// operator overloading <<
	std::cout << pass;

	// inline function
	std::cout << min(10, 20) << std::endl;
}