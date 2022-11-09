#include "Object-Oriented_Design.h"

class Bob {
private:
	int s1;
public:
	Bob(int s);
	~Bob();
};

class InternetProcess
{
public:
	InternetProcess(int m);
};

class Alice {
public:
	Alice(int s);
};

Bob::Bob(int s)
{
	s1 = s;
	std::cout << "Message received " << s << std::endl;
}

Bob::~Bob()
{
	std::cout << "Message " << s1 << " destroyed" << std::endl;
}

InternetProcess::InternetProcess(int m)
{
	Bob b(m);
}

Alice::Alice(int s)
{
	InternetProcess ip(s);
}

int SimulationMessages()
{
	int count = 5;
	while (count > 0)
	{
		Alice a(count);
		count--;
	}
	return EXIT_SUCCESS;
}