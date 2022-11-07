#include "Object-Oriented_Design.h"

class Person {						// Person (base class)
private:
	std::string name;				// name
	std::string idNum;				// university ID number
public:
	//...
	Person(const std::string name, const std::string idNum);
	void print();					// print information
	std::string getName();			// retrieve name
};

class Student : public Person {		// Student (derived from Person)
private:
	std::string major;				// major subject
	int			gradYear;			// graduation year
public:
	// ...
	Student(const std::string name, const std::string idNum, const std::string major, const int gradYear);
	void print();					// print information
	void changeMajor(const std::string& newMajor);	//change major
};

Person::Person(const std::string name, const std::string idNum) : name(name), idNum(idNum) {};

Student::Student(const std::string name, const std::string idNum, const std::string major, const int gradYear) : Person(name, idNum), major(major), gradYear(gradYear) {};

void Person::print()										// definition of Person print
{
	std::cout << "Name " << this->name << std::endl;
	std::cout << "IDnum " << this->idNum << std::endl;
}

void Student::print()										// definition of Student print
{
	Person::print();										// first print Person information
	std::cout << "Major " << this->major << std::endl;
	std::cout << "Year " << this->gradYear << std::endl;
}

//void Student::printName()
//{
//	std::cout << name << "\n";								// ERROR! name is private to Person
//}

void InheranceAndPolymorphism()
{
	Person person("Daniel", "12-345");				// declare a Person
	Student student("Bob", "98-764", "Math", 2021);	// declare a Student

	std::cout << student.getName() << std::endl;	// invoked Person::getName()
	person.print();									// invoked Person::print()
	student.print();								// invoked Student::print()
	//person.changeMajor("Physics");					// ERROR!
	student.changeMajor("English");					// okay
}