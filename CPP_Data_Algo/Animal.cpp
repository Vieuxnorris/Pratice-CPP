#include "Object-Oriented_Design.h"

class Animal {
public:

private:

};

class RuntimeException {
public:
	RuntimeException(const std::string& err) { errorMsg = err; }
	std::string getMessage() const { return errorMsg; }
private:
	std::string errorMsg;
};