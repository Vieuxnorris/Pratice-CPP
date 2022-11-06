#include "Cpp_Prime.h"
#include <vector>

enum MealType { NO_PREF, REGULAR, LOW_FAT, VEGETARIAN };

class Passenger {				// Passenger (as a class)
public:
	Passenger();				// constructor
	Passenger(const std::string& nm, MealType mp, const std::string& ffn = "NONE");
	Passenger(const Passenger& pass);	// copy constructor
	bool isFrequentFlyer() const;	// is this frequent flyer ?
									// make this a frequent flyer
	void makeFrequentFlyer(const std::string& newFreqFlyerNo);
	// ... other member functions
private:
	std::string name;			// passenger name
	MealType mealPref;			// meal preference
	bool isFreqFlyer;			// is a frequent flyer ?
	std::string freqFlyerNo;	// frequent flyer number
};

// Passenger Methodes

Passenger::Passenger()
{
	name = "--NO NAME--";
	mealPref = NO_PREF;
	isFreqFlyer = false;
	freqFlyerNo = "NONE";
}

Passenger::Passenger(const std::string& nm, MealType mp, const std::string& ffn) : name(nm), mealPref(mp), isFreqFlyer(ffn != "NONE")
{
	freqFlyerNo = ffn;
}

Passenger::Passenger(const Passenger& pass)
{
	name = pass.name;
	mealPref = pass.mealPref;
	isFreqFlyer = pass.isFreqFlyer;
	freqFlyerNo = pass.freqFlyerNo;
}

bool Passenger::isFrequentFlyer() const
{
	return isFreqFlyer;
}

void Passenger::makeFrequentFlyer(const std::string& newFreqFlyerNo)
{
	isFreqFlyer = true;
	freqFlyerNo = newFreqFlyerNo;
}


/*
* stack				Container with last-in, first-out access
* queue				Container with first-in, first-out access
* deque				Double-ended queue
* vector			Resizeable array
* list				Doubly linked list
* priority_queue	Queue ordered by value
* set				Set
* map				Associative array (dictionary)
*/

void Standard_Template_Library(void)
{
	std::vector<int> scores(100);				// 100 integer scores
	std::vector<char> buffer(500);				// buffer of 500 characters
	std::vector<Passenger> passenList(20);		// list of 20 Passengers

	int i = 1;
	std::cout << scores[i];						// index (range unchecked)
	buffer.at(i) = buffer.at(2 * i);	// index (range checked)
	std::vector<int> newScores = scores;		// copy scores to newScores
	scores.resize(scores.size() + 10);	// add room for 10 more elements

	/* std::string options
	* s.find(p)					Return the index of first occurrence of string p in s
	* s.find(p,i)				Return the index of first occurrence of string p in s on or after position i
	* s.substr(i,m)				Return the substring starting at position i of s and consisting of m characters
	* s.insert(i,p)				Insert string p just prior to index i in s
	* s.erase(i,m)				Remove the substring of length m starting at index i
	* s.replace(i,m,p)			Replace the substring of length m starting at index i with p
	* getline(is,s)				Read a single line from the input stream 'is' and store the result in s
	*/

	std::string s = "a dog";									// "a dog"
	s += " is a dog";											// "a dog is a dog"
	std::cout << s.find("dog");								// 2
	std::cout << s.find("dog", 3);						// 11
	std::cout << (s.find("doug") == std::string::npos);		// true
	std::cout << s.substr(7, 5);						// "s a d"
	s.replace(2, 3, "frog");						// "a frog is a dog"
	s.erase(6, 3);									// "a frog a dog"
	s.insert(0, "is ");									// "is a frog a dog"
	std::cout << (s == "is a frog a dog");						// true
	std::cout << (s < "is a frog a toad");						// true
	std::cout << (s < "is a frog a cat");						// false
}