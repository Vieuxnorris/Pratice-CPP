#include "Object-Oriented_Design.h"

// class

class Progression {										// a generic progression
public:

	Progression(long f = 0) : first(f), cur(f) {}		// constructor
	virtual ~Progression() {}							// destructor
	void printProgression(int n);						// print the first n values

protected:

	virtual long firstValue();							// reset
	virtual long nextValue();							// advance

	long first;											// first value
	long cur;											// current value
};

class ArithProgression : public Progression {			// arithmetic progression
public:
	ArithProgression(long i = 1);						// constructor
protected:
	virtual long nextValue();							// advance

	long inc;											// increment
};

class GeomProgression : public Progression {
public:
	GeomProgression(long b = 2);						// constructor
protected:
	virtual long nextValue();							// advance

	long base;											// base value
};

class FibonacciProgression : public Progression {
public:
	FibonacciProgression(long f = 0, long s = 1);		// constructor
protected:
	virtual long firstValue();							// reset
	virtual long nextValue();							// advance
	
	long second;										// second value
	long prev;											// previous value
};

// methodes Progression

void Progression::printProgression(int n)				// print n values
{
	std::cout << firstValue();							// print the first
	for (int i = 2; i <= n; i++)						// print 2 through n
		std::cout << ' ' << nextValue();
	std::cout << std::endl;
}

long Progression::firstValue()							// reset
{
	cur = first;
	return cur;
}

long Progression::nextValue()							// advance
{
	return ++cur;
}

// methodes ArithProgression

ArithProgression::ArithProgression(long i) : Progression(), inc(i) {};		// constructor

long ArithProgression::nextValue()											// advance by adding
{
	cur += inc;
	return cur;
}

// methodes GeomProgression

GeomProgression::GeomProgression(long b) : Progression(1), base(b) {};		// constructor

long GeomProgression::nextValue()											// advance by multiplying
{
	cur *= base;
	return cur;
}

// methodes FibonacciProgression

FibonacciProgression::FibonacciProgression(long f, long s) : Progression(f), second(s), prev(second - first) {};

long FibonacciProgression::firstValue()										// reset
{
	cur = first;
	prev = second - first;													// create fictious prev
	return cur;
}

long FibonacciProgression::nextValue()
{
	long temp = prev;
	prev = cur;
	cur += temp;
	return cur;
}



// Test program for the progression classes
int ExampleOfInheritance()
{
	Progression* prog;
	// test ArithProgression

	std::cout << "Arithmetic progression with default increment:\n";
	prog = new ArithProgression();
	prog->printProgression(10);
	std::cout << "Arithmetic progression with increment 5:\n";
	prog = new ArithProgression(5);
	prog->printProgression(10);

	// test GeomProgression

	std::cout << "Geometric progression with default base:\n";
	prog = new GeomProgression();
	prog->printProgression(10);
	std::cout << "Geometric progression with base 3:\n";
	prog = new GeomProgression(3);
	prog->printProgression(10);

	// test FibonacciProgression

	std::cout << "Fibonacci progression with default start values:\n";
	prog = new FibonacciProgression();
	prog->printProgression(10);
	std::cout << "Fibonacci progression with start values 4 and 6:\n";
	prog = new FibonacciProgression(4, 6);
	prog->printProgression(10);
	return EXIT_SUCCESS;												// successful execution

}