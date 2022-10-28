#include "Cpp_Prime.h"

struct Passenger {
	std::string name;
};

bool evenSum(int a[], int n) // function definition
{
	int sum = 0;
	for (int i = 0; i < n; i++) // sum the array elements
		sum += a[i];
	return (sum % 2) == 0; // returns true if sum is even
}

void f(int value, int& ref) // one value and one reference
{
	value++;							// no effect on the actual argument
	ref++;								// modifies the actual argument 
	std::cout << value << std::endl;	// outputs 2
	std::cout << ref << std::endl;		// outputs 6
}

// Constant references as arguments
/*
void someFunction(const Passenger& pass)
{
	pass.name = "new name"; // ILLEGAL !!! pass is declared const
}
*/
void Function(void)
{
	int list[] = { 4,2,7,8,5,1 };
	bool result = evenSum(list, 6); // invoke the function
	if (result)
		std::cout << "the sum is even\n";
	else
		std::cout << "the sum is odd\n";

	// argument Passing

	int cat = 1;
	int dog = 5;
	f(cat, dog);
	std::cout << cat << std::endl;
	std::cout << dog << std::endl;
}