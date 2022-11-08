#include "Object-Oriented_Design.h"

class MathException {													// generic math exception
public:
	MathException(const std::string& err) : errMsg(err) {}				// constructor
	std::string getError() { return errMsg; }							// access error message
private:
	std::string errMsg;													// error message
};

class ZeroDivide : public MathException {
public:
	ZeroDivide(const std::string& err) : MathException(err) {}			// divide by zero
};

class NegativeRoot : public MathException {
public:
	NegativeRoot(const std::string& err) : MathException(err) {}		// negative square root
};

void calculator() throw(ZeroDivide, NegativeRoot) {
	// function body ...
}

void func1();															// can throw any exception
void func2() throw();													// can throw no exception


class RuntimeException {												// generic run-time exception
public:
	RuntimeException(const std::string& err) { errorMsg = err; }
	std::string getMessage() const { return errorMsg; }
private:
	std::string errorMsg;
};

int ExceptionObject()
{
	try {
		// ... application computations
		int divisor = 0;
		std::cin >> divisor;
		if (static_cast<int>(divisor) == 0)												// attempt to divide by 0 ?
			throw ZeroDivide("Divide by zero in Modulo X");
	}
	catch (ZeroDivide& zde)
	{
		// handle division by zero
		std::cout << zde.getError() << std::endl;
	}
	catch (MathException& me)
	{
		// handle any math exception other than division by zero
		std::cout << me.getError() << std::endl;
	}
	return EXIT_SUCCESS;
}