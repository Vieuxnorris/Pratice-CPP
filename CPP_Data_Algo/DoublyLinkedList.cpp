#include "Array_Linked_List_Recursion.h"

class DLinkedList;
typedef std::string Elem;	// list element type

class DNode {	// doubly linked list node
private:
	Elem elem;	// node element value
	DNode* prev;	// previous node in list
	DNode* next;	// next node in list
	friend class DLinkedList;	// allow DLinkedList access
};

class DLinkedList {		// doubly linked list
public:
	DLinkedList();	// constructor
	~DLinkedList();	// destructor
	bool empty() const;	// is list empty ?
	const Elem& front() const;	// get front element
	const Elem& back() const;	// get back element
	void addFront(const Elem& e);	// add to front of list
	void addBack(const Elem& e);	// add to back of list
	void removeFront();	// remove from front
	void removeBack();	// remove from back
	void listReverse(DLinkedList& L);
private:	// local type definitions
	DNode* header;	// list sentinels
	DNode* trailer;
protected:	// local utilities
	void add(DNode* v, const Elem& e);	// insert new node before v
	void remove(DNode* v);	// remove node v
};

DLinkedList::DLinkedList() : header(new DNode), trailer(new DNode)	// constructor - create sentinels
{
	header->next = trailer;		// have them point to each other
	trailer->prev = header;
}

DLinkedList::~DLinkedList()	// destructor
{
	while (!empty())	// remove all but sentinels
		removeFront();
	delete header;		// remove the sentinels
	delete trailer;
}

bool DLinkedList::empty() const		// is list empty ?
{
	return (header->next == trailer);
}

const Elem& DLinkedList::front() const	// get front element
{
	return header->next->elem;
}

const Elem& DLinkedList::back() const	// get back element
{
	return trailer->prev->elem;
}

void DLinkedList::add(DNode* v, const Elem& e)	// insert new node before v
{
	DNode* u = new DNode;	// create a new node for e
	u->elem = e;
	u->next = v;	// link u in between v
	u->prev = v->prev;	// ...and v->prev
	v->prev->next = u;	// v->prev->next = v->prev = u; no working :-(
	v->prev = u;
}

void DLinkedList::addFront(const Elem& e)	// add to front of list
{
	add(header->next, e);
}

void DLinkedList::addBack(const Elem& e)	// add to back of list
{
	add(trailer, e);
}

void DLinkedList::remove(DNode* v)	// remove node v
{
	DNode* u = v->prev;		// predecessor
	DNode* w = v->next;		// successor
	u->next = w;	// unlink v from list
	w->prev = u;
	delete v;
}

void DLinkedList::removeFront()	// remove from front
{
	remove(header->next);
}

void DLinkedList::removeBack()	// remove from back
{
	remove(trailer->prev);
}

void DLinkedList::listReverse(DLinkedList& L)		// reverse a list
{
	DLinkedList T;									// temporary list
	while (!empty())								// reverse L into T
	{
		Elem s = L.front();
		L.removeFront();
		T.addFront(s);
	}
	while (!T.empty())								// copy T back to L
	{
		Elem s = T.front();
		T.removeFront();
		L.addBack(s);
	}
}

int DoublyLinkedList()
{
	DLinkedList e;
	e.addFront("SFO");
	e.addFront("PVD");
	e.addFront("BWI");
	e.addFront("JFK");
	std::cout << e.front() << std::endl;
	e.listReverse(e);
	std::cout << e.front() << std::endl;

	return EXIT_SUCCESS;
}