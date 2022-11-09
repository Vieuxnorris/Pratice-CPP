#include "Object-Oriented_Design.h"

class Line {
public:
	Line(double xx = 0.0, double yy = 0.0) : a(xx), b(yy) {}
	double intersect(Line& obj);
	bool isParallel(Line& obj);
private:
	double a, b;
	bool parallel = false;
};

class RuntimeException {
public:
	RuntimeException(const std::string& err) { errorMsg = err; }
	std::string getMessage() const { return errorMsg; }
private:
	std::string errorMsg;
};

double Line::intersect(Line& obj) throw(RuntimeException)
{
	std::cout << "Line 1: y = " << this->a << "x + " << this->b << std::endl;
	std::cout << "Line 2: y = " << obj.a << "x + " << obj.b << std::endl;

	double x = 0.0;
	if (this->a == obj.a)
		throw RuntimeException("Lines are parallel");
	else
		x = -(obj.b - this->b) / (obj.a - this->a);
	return x;
}

bool Line::isParallel(Line& obj)
{
	double x = 0.0;
	try
	{
		x = this->intersect(obj);
	}
	catch (const char* err)
	{
		this->parallel = true;
		std::cerr << err << std::endl;
	}
	if (!parallel)
		std::cout << "Line intersect at x = " << x << std::endl;

	this->parallel = false;
	return parallel;
}

int Parallel()
{
	Line one(5.0, 10.0);
	Line two(5.0, 15.0);
	Line three(25.0, 10.0);
	Line four(5.0, 15.0);

	one.isParallel(two);
	three.isParallel(four);

	return EXIT_SUCCESS;
}