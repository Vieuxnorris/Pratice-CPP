#include "Object-Oriented_Design.h"

template<typename T>
class Bill {
public:
	Bill(T moneygift, T amount);
	void PrintMoneyBack(const Bill<T>& obj);
private:
	T wallet = 0;
};

class RuntimeException {
public:
	RuntimeException(const std::string& err) { errorMsg = err; }
	std::string getMessage() const { return errorMsg; }
private:
	std::string errorMsg;
};

template<typename T>
Bill<T>::Bill(T moneygift, T amount) : wallet(moneygift)
{
	try {
		if (moneygift < amount)
			throw RuntimeException("you don't have the money for the object");
		while (amount > 0)
		{
			if (amount > 100)
			{
				this->wallet -= 100;
				amount -= 100;
			}
			else if (amount >= 50 && amount <= 100)
			{
				this->wallet -= 50;
				amount -= 50;
			}
			else if (amount >= 20 && amount <= 50)
			{
				this->wallet -= 20;
				amount -= 20;
			}
			else if (amount >= 10 && amount <= 25)
			{
				this->wallet -= 10;
				amount -= 10;
			}
			else if (amount >= 1 && amount <= 10)
			{
				this->wallet -= static_cast<int>(amount);
				amount -= static_cast<int>(amount);
			}
			else if (amount >= 0.01 && amount <= 0.99)
			{
				this->wallet -= amount;
				amount -= amount;
			}
		}
	}
	catch (RuntimeException& err)
	{
		std::cout << err.getMessage() << std::endl;
	}
}

template<typename T>
void Bill<T>::PrintMoneyBack(const Bill<T>& obj)
{
	
	std::cout << "Money back -> " << obj.wallet << std::endl;
}

int BillPayement()
{
	std::cout << "Test BillPayement with int values\n";
	int intinputCharge, intinputAmount;
	intinputCharge = intinputAmount = 0;
	std::cin >> intinputCharge;
	std::cin >> intinputAmount;

	Bill<int> intwallet(intinputCharge, intinputAmount);
	intwallet.PrintMoneyBack(intwallet);

	std::cout << "Test BillPayement with float values\n";
	float floatinputCharge, floatinputAmount;
	floatinputCharge = floatinputAmount = 0.0;
	std::cin >> floatinputCharge;
	std::cin >> floatinputAmount;

	Bill<float> floatwallet(floatinputCharge, floatinputAmount);
	floatwallet.PrintMoneyBack(floatwallet);
	return EXIT_SUCCESS;
}