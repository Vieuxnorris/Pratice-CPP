#include "Cpp_Prime.h"
using std::string;

void C_style_Structures(void)
{
	enum MealType {NO_PREF, REGULAR, LOW_FAT, VEGETARIAN};
	
	struct Passenger {
		string name;
		MealType mealPref;
		bool isFreqFlyer;
		string freqFlyerNo;
	};

	Passenger pass = {"John Smith", REGULAR, true, "12345"};
	
	pass.name = "Pocahontas";
	pass.mealPref = LOW_FAT;
	std::cout << "Passenger: " << pass.name << std::endl;
	std::cout << "Meal Preference: " << pass.mealPref << std::endl;
	std::cout << "Is Frequent Flyer: " << pass.isFreqFlyer << std::endl;
	std::cout << "Frequent Flyer Number: " << pass.freqFlyerNo << std::endl;
}