#include "Object-Oriented_Design.h"
#include <vector>


class Complex {
public:
	double real, imaginary;
	Complex();
	Complex(double r, double i);

	Complex operator+(Complex& a2);
	Complex operator-(Complex& a2);
	Complex operator*(Complex& a2);
	void operator=(double value);
};

template<typename T>
class Vector {
public:
	int size;
	T additiveidentity, multiplicativeidentity;
	Vector(int n);
	Vector(int n, int t);
	std::vector<T> add(std::vector<T>, std::vector<T>);
	std::vector<T> substract(std::vector<T>, std::vector<T>);
	std::vector<T> multiply(std::vector<T>, T);
	T dotproduct(std::vector<T>, std::vector<T>);
};

Complex::Complex() : imaginary(0), real(0) {}

Complex::Complex(double r, double i) : real(r), imaginary(i) {}

Complex Complex::operator+(Complex& a2)
{
	Complex a;
	a.real = real + a2.real;
	a.imaginary = imaginary + a2.imaginary;
	return a;
}

Complex Complex::operator-(Complex& a2)
{
	Complex a;
	a.real = real - a2.real;
	a.imaginary = imaginary - a2.imaginary;
	return a;
}

Complex Complex::operator*(Complex& a2)
{
	Complex a;
	a.real = real * a2.real;
	a.imaginary = imaginary * a2.imaginary;
	return a;
}

void Complex::operator=(double value)
{
	real = value;
	imaginary = 0;
}

template<typename T>
Vector<T>::Vector(int t)
{
	if (t == 0)
		additiveidentity = 0;
	if (t == 1)
		multiplicativeidentity = 1;
}

template<typename T>
Vector<T>::Vector(int n, int t) : size(n) {}

template<typename T>
std::vector<T> Vector<T>::add(std::vector<T> e1, std::vector<T> e2)
{
	std::vector<T> result;

	for (int i = 0; i < e1.size(); i++)
	{
		result.push_back(e1[i] + e2[i]);
	}
	return result;
}

template<typename T>
std::vector<T> Vector<T>::substract(std::vector<T> e1, std::vector<T> e2)
{
	std::vector<T> result;

	for (int i = 0; i < e1.size(); i++)
	{
		result.push_back(e1[i] - e2[i]);
	}
	return result;
}

template<typename T>
std::vector<T> Vector<T>::multiply(std::vector<T> e1, T e2)
{
	std::vector<T> result;

	for (int i = 0; i < e1.size(); i++)
	{
		result.push_back(e1[i] * e2);
	}
	return result;
}

template<typename T>
T Vector<T>::dotproduct(std::vector<T> e1, std::vector<T> e2)
{
	T result;

	for (int i = 0; i < e1.size(); i++)
	{
		if (i == 0)
			result = e1[i] * e2[2];
		else
			result = result + (e1[i] * e2[i]);
	}
	return result;
}


int ComplexClass()
{
	int size;
	int intscalar;
	std::cout << "Enter the size of the vector: ";
	std::cin >> size;
	std::vector<int> intvetor, intvector1, intresultvector;
	std::vector<double> doublevector, doublevector1, doubleresultvector;
	std::vector<Complex> complexvector, complexvector1, complexresultvector;

	Vector<int> inttemplate(size, 0);
	Vector<double> doubletemplate(size, 0);
	Vector<Complex> complextemplate(size, 0);

	std::cout << "Enter the values of integer vector : \n";

	int x;
	for (int i = 0; i < size; i++)
	{
		std::cin >> x;
		intvetor.push_back(x);
	}

	std::cout << "Enter the values of second integer vector : \n";

	for (int i = 0; i < size; i++)
	{
		std::cin >> x;
		intvector1.push_back(x);
	}

	std::cout << "Enter the value of integer scalar : \n";
	std::cin >> intscalar;

	intresultvector = inttemplate.add(intvetor, intvector1);
	std::cout << "The resultant vector obtained" << "after adding two vectors is: \n";

	for (int i = 0; i < size; i++)
	{
		std::cout << intresultvector.at(i) << std::endl;
	}
	std::cout << "\n\n";

	intresultvector = inttemplate.substract(intvetor, intvector1);
	std::cout << "The resultant vector obtained" << "after subtracting two vectors is :\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << intresultvector.at(i) << std::endl;
	}
	std::cout << "\n\n";

	int intresult = inttemplate.dotproduct(intvetor, intvector1);
	std::cout << "The resultant vector obtained" << "after multiply scalar with first vector is :\n";
	std::cout << intresult;
	std::cout << "\n\n";




	return EXIT_SUCCESS;
}