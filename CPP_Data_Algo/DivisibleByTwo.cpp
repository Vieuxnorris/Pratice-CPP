#include "Object-Oriented_Design.h"
#include <vector>


template<typename T>
class Divisible {
public:
	Divisible(T n);
	void printNumberDivisible(const Divisible& obj);
private:
	T Number = 0;
	T buffer = 0;
	std::vector<T> SaveDiv;
};

class RuntimeException {
public:
	RuntimeException(const std::string& err) { errorMsg = err; }
	std::string getMessage() const { return errorMsg; }
private:
	std::string errorMsg;
};

template<typename T>
Divisible<T>::Divisible(T n)
{
	try
	{
		if ((n / 2) == false)
			throw RuntimeException("No divisible by 2");
		else
		{
			this->buffer = n;
			this->Number = n;
		}
	}
	catch (RuntimeException& err)
	{
		std::cout << err.getMessage() << std::endl;
	}

	try {
		while (static_cast<int>(this->Number / 2))
		{
			SaveDiv.push_back(this->Number / 2);
			this->Number /= 2;
			if (SaveDiv.size() > 50)
				throw RuntimeException("maximum allowed size");
		}
	}
	catch (RuntimeException& err)
	{
		std::cout << err.getMessage() << std::endl;
	}
}

template<typename T>
void Divisible<T>::printNumberDivisible(const Divisible<T>& obj)
{
	if (obj.SaveDiv.size() < 50)
		std::cout << "The number -> " << obj.buffer << " and divisible -> " << obj.SaveDiv.size() << " by two" << std::endl;
	else
		std::cout << "The number -> " << obj.buffer << " and divisible -> 'ERROR' by two" << std::endl;
}

int DivisibleByTwo()
{
	Divisible<int> intNumber(1);
	intNumber.printNumberDivisible(intNumber);
	Divisible<float> intNumber2(600);
	intNumber2.printNumberDivisible(intNumber2);

	Divisible<double> doubleNumber(6.0);
	doubleNumber.printNumberDivisible(doubleNumber);

	return EXIT_SUCCESS;
}