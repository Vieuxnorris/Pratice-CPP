#include "Cpp_Prime.h";

enum MealType { NO_PREF, REGULAR, LOW_FAT, VEGETARIAN };

class Book {
public:
	class Bookmark {
		// ...	(Bookmark definition here)
	};
	// ... (Remainder of Book definition)
};

class SomeClass {
private:
	int secret;
public:
	//...											// give << operator access to secret
	friend std::ostream& operator<<(std::ostream& out, const SomeClass& x);
};

class Vect {								// a vector class
public:										
	Vect(int n = 10);							// constructor, given size
	Vect(const Vect& a);
	~Vect();								// destructor
	// ... other public members omitted
private:
	double coord[3];						// storage for coordinates
	friend class Matrix;					// give Matrix access to coord
	int*	data;							// an array holding the vector
	int		size;							// number of array entries
};

class Matrix {								// a 3x3 matrix
public:
	Vect multiply(const Vect& v);			// multiply by vector v
	// ... other public members omitted
private:
	double a[3][3];							// matrix entries
};

class Counter {					// a simple counter
public:
	Counter();					// initialization
	int getCount();				// get the current count
	void increaseBy(int x);		// add x to the count
private:
	int count;					// the counter's value
};

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

// SomeClass Methodes

std::ostream& operator<<(std::ostream& out, const SomeClass& x)
{
	std::cout << x.secret;
}

// Vect Methodes

Vect::Vect(int n)				// constructor
{
	size = n;					
	data = new int[n];			// allocate array
}

Vect::Vect(const Vect& a)				// copy constructor from a
{
	size = a.size;						// copy sizes
	data = new int[size];				// allocate new array
	for (int i = 0; i < size; i++)		// copy the vector contents
		data[i] = a.data[i];
}

Vect& Vect::operator=(const Vect& a)		// assignement operator from a
{
	if (this != &a)							// avoid self-assignement
	{
		delete[] data;						// delete old array
		size = a.size;						// set new array
		data = new int[size];				// allocate new array
		for (int i = 0; i < size; i++)		// copy the vector contents
			data[i] = a.data[i];
	}
	return *this;
}

Vect::~Vect()					// destructor
{
	delete[] data;				// free the allocated array
}

Vect Matrix::multiply(const Vect& v)				// multiply by vector v
{
	Vect w;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			w.coord[i] += a[i][j] * v.coord[j];		// access to coord allowed
	}
	return w;
}

// Counter Methodes

Counter::Counter()				// constructor
{
	count = 0;
}

int Counter::getCount()			// get current count
{
	return count;
}

void Counter::increaseBy(int x)	// add x to the count
{
	count += x;
}

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

// Main function

void Classes(void)
{
	Counter ctr;									// an instance of Counter
	std::cout << ctr.getCount() << std::endl;		// prints the initial value (0)
	ctr.increaseBy(3);								// increase by 3
	std::cout << ctr.getCount() << std::endl;		// prints 3
	ctr.increaseBy(5);								// increase by 5
	std::cout << ctr.getCount() << std::endl;		// prints 8

	Passenger pass;									// pass is a Passenger
	if (!pass.isFrequentFlyer())					// not already a frequent flyer ?
		pass.makeFrequentFlyer("392953");			// set pass's freq flyer number
	//pass.name = "Joe Blow";						// ILLEGAL! name is private


	Passenger p1; // default constructor
	Passenger p2("John Smith", VEGETARIAN, "293145"); // 2nd constructor
	Passenger p3("Pocahontas", REGULAR); // not a frequent flyer
	Passenger p4(p3); // copied from p3
	Passenger p5 = p2; // copied from p2
	Passenger* pp1 = new Passenger; // default constructor
	Passenger* pp2 = new Passenger("Joe Blow", NO_PREF); // 2nd constr.
	Passenger pa[20]; // uses the default constructor

	Vect a(100);			// a is a vector of size 100
	Vect b = a;				// initialize b from a (DANGER!)
	Vect c;					// c is a vector (default size 10)
	c = a;					// assign a to c (DANGER!)

	/*
	* Counter ctr;									// ctr is an instance of Counter
	* std::cout << ctr.count << std::endl;			// ILLEGAL - count is private
	*/
}