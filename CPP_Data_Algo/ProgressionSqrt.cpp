#include "Object-Oriented_Design.h"

class ProgressionClone {										// a generic progression
public:

	ProgressionClone(long f = 0) : first(f), cur(f) { }		// constructor
	virtual ~ProgressionClone() {}							// destructor
	void printProgression(int n);						// print the first n values
protected:

	virtual long firstValue();							// reset
	virtual long nextValue();							// advance

	double first;											// first value
	double cur;											// current value
};

class SqrtProgression : public ProgressionClone
{
public:
	SqrtProgression(long val1, long val2);
protected:
	virtual long firstValue();
	virtual long nextValue();

	double second;
	double prev;
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

SqrtProgression::SqrtProgression(long val1=2, long val2=200)
{
	first = val1;
	second = val2;
}

long SqrtProgression::firstValue()
{
	cur = first;
	prev = first + second;
	return cur;
}

long SqrtProgression::nextValue()
{
	long temp = cur;
	cur = sqrt(prev);
	prev += temp;
	return cur;
}

int ProgressionSqrt()
{
	SqrtProgression* prog = new SqrtProgression(4,8);
	prog->printProgression(10);
	return EXIT_SUCCESS;
}