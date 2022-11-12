#include "Object-Oriented_Design.h"

class Base {
private:
	int priv;
protected:
	int prot;
public:
	int publ;
};

class Derived : public Base {
	void someMemberFunction()
	{
		//std::cout << priv;		// ERROR: private member
		std::cout << prot;			// okay
		std::cout << publ;			// okay
	}
};

class Unrelated {
	Base X;

	void anotherMemberFunction()
	{
		//std::cout << X.priv;		// ERROR: private member
		//std::cout << X.prot;		// ERROR: protected member
		std::cout << X.publ;		// okay
	}
};

class Person {						// Person (base class)
private:
	std::string name;				// name
	std::string idNum;				// university ID number
public:
	//...
	virtual ~Person();
	Person(const std::string name, const std::string idNum);
	virtual void print();									// print information
	std::string getName() const { return name; }			// retrieve name
};

class Student : public Person {		// Student (derived from Person)
private:
	std::string major;				// major subject
	int			gradYear;			// graduation year
public:
	// ...
	~Student();
	Student(const std::string name, const std::string idNum, const std::string major, const int gradYear);
	virtual void print();					// print information
	virtual void changeMajor(const std::string& newMajor);	//change major
};

Person::~Person() {};

Person::Person(const std::string name, const std::string idNum) : name(name), idNum(idNum) {};

Student::~Student() {};

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

void Student::changeMajor(const std::string& newMajor)
{
	this->major = newMajor;
}


//void Student::printName()
//{
//	std::cout << name << "\n";								// ERROR! name is private to Person
//}

void InheranceAndPolymorphism()
{
	Person person("Daniel", "12-345");				// declare a Person
	Student* s = new Student("Carol", "34-927", "Physics", 2014);	// declare a Student
	Student student("test", "34-927", "Math", 2017);

	Person* pp[100];											// array of 100 Person pointers
	pp[0] = new Person("Daniel", "12-345");						// add a Person (details omitted)
	pp[1] = new Student("Carol1234", "34-927", "Physics", 2014);	// add a Student (details omitted)

	std::cout << pp[1]->getName() << '\n';						// okay
	pp[0]->print();												// calls Person::print()
	pp[1]->print();												// also calls Person::print() (!but with virtual function work)
	Student* sp = dynamic_cast<Student*>(pp[1]);				// cast pp[1] to Student*
	sp->changeMajor("English");									// now changeMajor is legal
	pp[1]->print();

	for (int i = 0; i < 2; i++)
	{
		Student* sp = dynamic_cast<Student*>(pp[i]);
		if (sp != NULL)											// cast succeeded ?
			sp->changeMajor("Undecided");						// change major
	}
	std::cout << std::endl;
	pp[0]->print();
	pp[1]->print();

	//std::cout << student.getName() << std::endl;	// invoked Person::getName()
	person.print();									// invoked Person::print()
	s->print();										// invoked Student::print()
	//person.changeMajor("Physics");					// ERROR!
	student.changeMajor("English");					// okay
	delete s; // calls ˜Student() then ˜Person()
}