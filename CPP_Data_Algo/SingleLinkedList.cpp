#include "Array_Linked_List_Recursion.h"

class Snode {
private:
	std::string elem;
	Snode* next;

	friend class SLinkedList;
};

class SLinkedList {
public:
	SLinkedList() : head(NULL) { }
	~SLinkedList();
	bool empty() const;
	const std::string& front() const;
	void addFront(const std::string& e);
	void removeFront();
private:
	Snode* head;
};

SLinkedList::~SLinkedList()
{
	while (!empty()) removeFront();
}

bool SLinkedList::empty() const
{
	return head == NULL;
}

const std::string& SLinkedList::front() const
{
	return head->elem;
}

void SLinkedList::addFront(const std::string& e)
{
	Snode* v = new Snode;
	v->elem = e;
	v->next = head;
	head = v;
}

void SLinkedList::removeFront()
{
	Snode* old = head;
	head = old->next;
	delete old;
}

int SingleLinkedList()
{
	SLinkedList e;
	e.addFront("MSP");
	std::cout << e.empty() << std::endl;
	e.removeFront();
	std::cout << e.empty() << std::endl;
	return EXIT_SUCCESS;
}