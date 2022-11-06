#include "CreditCard.h"

CreditCard::CreditCard(const std::string& no, const std::string& nm, int lim, double bal)
{
	number = no;
	name = nm;
	balance = bal;
	limit = lim;
}

// make a charge
bool CreditCard::chargeIt(double price)
{
	if (price + balance > double(limit))
		return false;						// over limit
	balance += price;
	return true;							// the charge goes through
}

// make a payment
void CreditCard::makePayment(double payment)
{
	balance -= payment;
}

// print card information
std::ostream& operator<<(std::ostream& out, const CreditCard& c)
{
	out << "Number = " << c.getNumber() << "\n"
		<< "Name = " << c.getName() << "\n"
		<< "Balance = " << c.getBalance() << "\n"
		<< "Limit = " << c.getLimit() << "\n";
	return out;
}