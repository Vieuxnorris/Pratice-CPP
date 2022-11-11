#include "Object-Oriented_Design.h"

template<typename T>
class AnimalClass {
public:
	AnimalClass(T force, std::string sexe, AnimalClass& a);
	~AnimalClass();

	std::ostream& operator<<(const AnimalClass& a);
protected:
	T force;
	bool attaque = false;
	std::string sexe;
};

template<typename T>
class Conversation {
public:
	Conversation(T force, std::string sexe, const AnimalClass a);
private:
};

class RuntimeException {
public:
	RuntimeException(const std::string& err) { errorMsg = err; }
	std::string getMessage() const { return errorMsg; }
private:
	std::string errorMsg;
};


template<typename T>
AnimalClass<T>::AnimalClass(T force, std::string sexe, AnimalClass& a) : force(force), sexe(sexe)
{
	if (this->sexe.compare(a.sexe))
	{
		this->attaque = true;
		a.sexe = true;
		std::cout << "Echange entre animal :" << "\n\n" << this << a;
	}
	else
		std::cout << "Echange entre animal :" << "\n\n" << this << a;
}

template<typename T>
AnimalClass<T>::~AnimalClass()
{
	std::cout << "Fin de la conversation" << std::endl;
}

template<typename T>
std::ostream& AnimalClass<T>::operator<<(const AnimalClass& a)
{
	out << "force : " << a.force << "\n"
		<< "sexe : " << a.sexe << "\n"
		<< "attaque ? " << a.attaque << '\n';
	return out;
}

template<typename T>
Conversation<T>::Conversation(T force, std::string sexe, const AnimalClass<T> a)
{
	AnimalClass<T> ours(force, sexe, a);
}


int Animal()
{

	return EXIT_SUCCESS;
}

