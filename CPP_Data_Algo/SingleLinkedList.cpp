#include "Array_Linked_List_Recursion.h"

// generic declaration class

template<typename T>
class SLinkedList;

template <typename T>
class SNode {
private:
	T elem;
	SNode<T>* next;
	friend class SLinkedList<T>;
};

template <typename T>
class SLinkedList {
public:
	SLinkedList();
	~SLinkedList();
	bool empty() const;
	const T& front() const;
	void addFront(const T& e);
	void removeFront();
private:
	SNode<T>* head;
};

template <typename T>
SLinkedList<T>::SLinkedList() : head(NULL) { }

template <typename T>
SLinkedList<T>::~SLinkedList()
{
	while (!empty())
		removeFront();
}

template <typename T>
bool SLinkedList<T>::empty() const
{
	return head == NULL;
}

template <typename T>
const T& SLinkedList<T>::front() const
{
	return head->elem;
}

template <typename T>
void SLinkedList<T>::addFront(const T& e)
{
	SNode<T>* v = new SNode<T>;
	v->elem = e;
	v->next = head;
	head = v;
}

template <typename T>
void SLinkedList<T>::removeFront()
{
	SNode<T>* old = head;
	head = old->next;
	delete old;
}

// classique declaration class and function

class StringNode {									// a node in a list of strings
private:
	std::string elem;								// element value
	StringNode* next;								// next item in the list

	friend class StringLinkedList;					// provide StringLinkedList access
};

class StringLinkedList {							// a linked list of strings
public:
	StringLinkedList() : head(NULL) { }				// empty list constructor
	~StringLinkedList();							// destructor
	bool empty() const;								// is list empty?
	const std::string& front() const;				// get front element
	void addFront(const std::string& e);			// add to front of list
	void removeFront();
private:
	StringNode* head;								// pointer to the head of list
};

StringLinkedList::~StringLinkedList()				// destructor
{
	while (!empty()) removeFront();
}

bool StringLinkedList::empty() const				// is list empty ?
{
	return head == NULL;
}

const std::string& StringLinkedList::front() const			// get front element
{
	return head->elem;
}

void StringLinkedList::addFront(const std::string& e)		// add to front of list
{
	StringNode* v = new StringNode;							// create new node
	v->elem = e;											// store data
	v->next = head;											// head now follows v
	head = v;												// v is now the head
}

void StringLinkedList::removeFront()						// remove font item
{
	StringNode* old = head;									// save current head
	head = old->next;										// skip over old head
	delete old;												// delete the old head
}

// main function

int SingleLinkedList()
{
	StringLinkedList e;
	e.addFront("MSP");
	std::cout << e.empty() << std::endl;
	e.removeFront();
	std::cout << e.empty() << std::endl;

	SLinkedList<std::string> a;
	a.addFront("MSP");
	std::cout << a.empty() << std::endl;
	a.removeFront();
	std::cout << a.empty() << std::endl;
	return EXIT_SUCCESS;
}