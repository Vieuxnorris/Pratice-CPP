#include "Object-Oriented_Design.h"

inline int integerMin(int a, int b) { return (a < b ? a : b); }			// returns the minimum of a and b

template <typename T>
T genericMin(T a, T b)													// returns the minimum of a and b for any type
{
	return (a < b ? a : b);
}

template <typename T>
class BasicVector {														// a simple vector class
public:
	BasicVector(int capac = 10);										// constructor
	T& operator[](int i) { return a[i]; }								// access element at index i
private:
	T* a;																// array storing the elements
	int capacity;														// length of array a
};

template <typename T>
BasicVector<T>::BasicVector(int capac)									// constructor
{
	this->capacity = capac;
	this->a = new T[this->capacity];									// allocate array storage
}

int FunctionTemplates()
{
	std::cout << genericMin(3, 4) << " "								//  = genericMin<int>(3,4)
		<< genericMin(1.1, 3.1) << " "									//  = genericMin<double>(1.1,3.1)
		<< genericMin('t', 'g') << std::endl;							//  = genericMin<char>('t','g')

	BasicVector<int> iv(5);												// vector of 5 integers
	BasicVector<double> dv(20);											// vector of 20 doubles
	BasicVector<std::string> sv(10);									// vector of 10 strings

	iv[3] = 8;
	dv[14] = 2.5;
	sv[7] = "hello";

	BasicVector<BasicVector<int> > xv(5);								// a vector of vectors

	xv[2][8] = 15;

	return EXIT_SUCCESS;
}