#include "Object-Oriented_Design.h"

class A {
public:
	int x;
};

class B : public A {
protected:
	int x;
};

class C : public B {
protected:
	int x;
public:
	void setxInA(C*);
};

void C::setxInA(C* p)
{
	dynamic_cast<A*>(p)->x = 5;
}

int setcBaseClass()
{
	C* p = new C;

	p->setxInA(p);
	std::cout << dynamic_cast<A*>(p)->x;
	return EXIT_SUCCESS;
}