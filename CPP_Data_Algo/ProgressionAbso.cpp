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

class AbsoProgression : public ProgressionClone2
{
public:
	AbsoProgression(long val1, long val2);
protected:
	virtual long firstValue();
	virtual long nextValue();

	long second;
	long prev;
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

AbsoProgression::AbsoProgression(long val1 = 2, long val2 = 200) : ProgressionClone2(val1)
{
	first = val1;
	second = val2;
}

long AbsoProgression::firstValue()
{
	cur = first;
	prev = first + second;
	return cur;
}

long AbsoProgression::nextValue()
{
	long temp = cur;
	if (prev > cur)
		cur = prev - cur;
	else
		cur = cur - prev;
	prev = temp;
	return cur;
}

int ProgressionAbso()
{
	AbsoProgression* prog = new AbsoProgression(4, 20);
	prog->printProgression(10);
	return EXIT_SUCCESS;
}