#include "Object-Oriented_Design.h"

class ProgressionClone2 {										// a generic progression
public:

	ProgressionClone2(long f = 0) : first(f), cur(f) { }		// constructor
	virtual ~ProgressionClone2() {}							// destructor
	void printProgression(int n);						// print the first n values
protected:

	virtual long firstValue();							// reset
	virtual long nextValue();							// advance

	double first;											// first value
	double cur;											// current value
};

class SqrtProgression : public ProgressionClone2
{
public:
	SqrtProgression();
	SqrtProgression(long, long);
protected:
	virtual long initialValue();
	virtual long nextValue();

	double second;
	double prev;
};

void ProgressionClone2::printProgression(int n)				// print n values
{
	std::cout << firstValue();							// print the first
	for (int i = 2; i <= n; i++)						// print 2 through n
		std::cout << ' ' << nextValue();
	std::cout << std::endl;
}

long ProgressionClone2::firstValue()							// reset
{
	cur = first;
	return cur;
}

long ProgressionClone2::nextValue()							// advance
{
	return ++cur;
}

SqrtProgression::SqrtProgression()
{
	first = 2;
	second = 200;
}

SqrtProgression::SqrtProgression(long f, long s) : ProgressionClone2(f), second(s) {}

long SqrtProgression::initialValue()
{
	cur = second;
	return cur;
}

long SqrtProgression::nextValue()
{
	cur += sqrt(second);
	return cur;
}

int ProgressionSqrt()
{
	SqrtProgression* prog = new SqrtProgression(4, 8);
	prog->printProgression(10);
	return EXIT_SUCCESS;
}