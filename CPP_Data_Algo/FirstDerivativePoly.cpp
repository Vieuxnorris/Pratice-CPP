#include "Object-Oriented_Design.h"
#include <sstream>


int FirstDerivativePoly()
{
	int terms;
	std::string derivative = "0", var = "x^";
	std::cout << "Enter the number of terms in the polynomial f(x): ";

	std::cin >> terms;
	const int count = terms;

	while (terms >= 1)
	{
		std::stringstream cs, es;
		std::string poly;
		int coef = 1, exp = 1;
		std::string cof = "", expo = "";
		bool flag = false;

		std::cout << "Enter term: ";
		std::getline(std::cin, poly);

		for (int i = 0; i < poly.length(); i++)
		{
			if (poly[i] == 32)
				poly = poly.erase(i, 1);
		}

		for (int i = 0; i < poly.length(); i++)
		{
			if (poly[i] == '-' && flag == false)
			{
				coef *= -1;
				i++;
			}
			if (poly[i] == '-' && flag == true)
			{
				exp *= -1;
				i++;
			}

			if (isdigit(poly[i]) && flag == false)
				cof = cof + poly[i];
			if (isdigit(poly[i]) && flag == true)
				expo = expo + poly[i];

			if (isalpha(poly[i]))
				flag = true;
		}

		coef *= atoi(cof.c_str());
		exp *= atoi(expo.c_str());
		int pro = coef * exp;
		cs << pro;
		std::string c = cs.str();
		exp--;
		es << exp;
		std::string e = es.str();

		if (pro != 0)
		{
			if (pro < 0 && count != terms)
				derivative = derivative.erase(derivative.length() - 1, 1);
			if (exp != 0)
				derivative = derivative + c + var + e + "+";
			else
				derivative = derivative + c + "+";
		}
		terms--;

		if (terms == 0)
		{
			derivative = derivative.erase(0, 1);
			derivative = derivative.erase(derivative.length() - 1, 1);
		}
	}
	std::cout << "Derivative of the polynomial is : " << derivative << std::endl;
	return EXIT_SUCCESS;
}