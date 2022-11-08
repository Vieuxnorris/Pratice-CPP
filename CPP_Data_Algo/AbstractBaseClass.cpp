#include "Object-Oriented_Design.h"

class Stack {									// stack interface as an abstract class
public:
	virtual bool isEmpty() const = 0;			// is the stack empty ?
	virtual void push(int x) = 0;				// push x onto the stack
	virtual int pop() = 0;						// pop the stack and return result
};

class ConcreteStack : public Stack {			// implements Stack
public:
	virtual bool isEmpty() const { return true; }	// implementation of members
	virtual void push(int x) { }				// ... (details omitted)
	virtual int pop() { return 1; }
private:
	// ...										// member data for the implementation

};

int AbstractBaseClass()
{
	ConcreteStack CS;
	std::cout << CS.isEmpty() << std::endl;

	return EXIT_SUCCESS;
}
