#include "Object-Oriented_Design.h"

class ProgressionClone {										// a generic progression
public:

	ProgressionClone(long f = 0) : first(f), cur(f) { }		// constructor
	virtual ~ProgressionClone() {}							// destructor
	void printProgression(int n);						// print the first n values
protected:

	virtual long firstValue();							// reset
	virtual long nextValue();							// advance

	long first;											// first value
	long cur;											// current value
};

class AbsoProgression : public ProgressionClone
{
public:
	AbsoProgression();
	AbsoProgression(long, long);
protected:
	virtual long initialValue();
	virtual long nextValue();

	long second;
	long prev;
};

void ProgressionClone::printProgression(int n)				// print n values
{
	std::cout << firstValue();							// print the first
	for (int i = 2; i <= n; i++)						// print 2 through n
		std::cout << ' ' << nextValue();
	std::cout << std::endl;
}

long ProgressionClone::firstValue()							// reset
{
	cur = first;
	return cur;
}

long ProgressionClone::nextValue()							// advance
{
	return ++cur;
}

AbsoProgression::AbsoProgression()
{
	first = 2;
	second = 200;
}

AbsoProgression::AbsoProgression(long f, long s) : ProgressionClone(f), second(s) {}

long AbsoProgression::initialValue()
{
	cur = second;
	return cur;
}

long AbsoProgression::nextValue()
{
	long temp = abs(first - second);
	cur += temp;
	return cur;
}

int ProgressionAbso()
{
	AbsoProgression* prog = new AbsoProgression(4,8);
	prog->printProgression(10);
	return EXIT_SUCCESS;
}