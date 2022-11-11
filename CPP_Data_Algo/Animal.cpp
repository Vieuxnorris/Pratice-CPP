#include "Object-Oriented_Design.h"

template<typename T>
class AnimalClass {
public:
	AnimalClass(T force, std::string sexe, AnimalClass& a);
	AnimalClass(T force, std::string sexe) : force(force), sexe(sexe) {}
	~AnimalClass();

	friend std::ostream& operator<<(std::ostream& out, AnimalClass& a);
private:
	T force;
	bool attaque = false;
	std::string sexe;
};

template<typename T>
class Conversation {
public:
	Conversation(int m ,T force, std::string sexe, AnimalClass<T> a);
};

std::ostream& operator<<(std::ostream& out, AnimalClass<float>& a)
{
	out << "force : " << a.force << "\n"
		<< "sexe : " << a.sexe << "\n"
		<< "attaque ? " << a.attaque << "\n";
	return out;
}

template<typename T>
AnimalClass<T>::AnimalClass(T force, std::string sexe, AnimalClass& a)
{
	this->force = force;
	this->sexe = sexe;
	if (this->sexe.compare(a.sexe) == 0)
	{
		this->attaque = true;
		a.attaque = true;
		std::cout << "Echange entre animal combat : " << '\n' << a
			<< "force : " << this->force << "\n"
			<< "sexe : " << this->sexe << "\n"
			<< "attaque ? " << this->attaque << "\n\n";
		if (this->force > a.force)
			std::cout << "Animal 1 gagne" << std::endl;
		else if (this->force < a.force)
			std::cout << "Animal 2 gagne" << std::endl;
	}
	else
	{
		std::cout << "Echange entre animal normal :" << '\n' << a
			<< "force : " << this->force << "\n"
			<< "sexe : " << this->sexe << "\n"
			<< "attaque ? " << this->attaque << "\n\n";
	}
}

template<typename T>
AnimalClass<T>::~AnimalClass()
{
	std::cout << "Fin de la conversation" << std::endl;
}

template<typename T>
Conversation<T>::Conversation(int m, T force, std::string sexe, AnimalClass<T> a)
{
	for (int i = 0; i < m; i++)
	{
		AnimalClass<T> ours(force, sexe, a);
	}
}


int Animal()
{
	AnimalClass<float> ours(200.0, "male");
	Conversation<float> ours2(5, 100, "male", ours);
	return EXIT_SUCCESS;
}
