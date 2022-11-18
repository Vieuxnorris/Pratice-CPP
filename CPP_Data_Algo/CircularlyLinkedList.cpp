#include "Array_Linked_List_Recursion.h"

typedef std::string Elem;		// element type
class CircleList;

class CNode {					// circularly linked list node
private:
	Elem elem;					// linked list element value
	CNode* next;				// next item in the list

	friend class CircleList;	// provide CircleList access
};

class CircleList {				// a curcularity linked list
public:
	CircleList();				// constructor
	~CircleList();				// destructor
	bool empty() const;			// is list empty ?
	const Elem& front() const;	// element at cursor
	const Elem& back() const;	// element following cursor
	void advance();				// advance cursor
	void add(const Elem& e);	// add after cursor
	void remove();				// remove node after cursor
private:
	CNode* cursor;				// the cursor
};


CircleList::CircleList() : cursor(NULL) {}

CircleList::~CircleList()
{
	while (empty())
		remove();
}

bool CircleList::empty() const
{
	return cursor == NULL;
}

const Elem& CircleList::back() const
{
	return cursor->elem;
}

const Elem& CircleList::front() const
{
	return cursor->next->elem;
}

void CircleList::advance()
{
	cursor = cursor->next;
}

void CircleList::add(const Elem& e)		// add after cursor
{
	CNode* v = new CNode;				// create a new node
	v->elem = e;
	if (cursor == NULL)					// list is empty ?
	{
		v->next = v;					// v points to itself
		cursor = v;						// cursor points to v
	}
	else
	{									// list is nonempty ?
		v->next = cursor->next;			// link in v after cursor
		cursor->next = v;
	}
}

void CircleList::remove()				// remove node after cursor
{
	CNode* old = cursor->next;			// the node being removed
	if (old == cursor)					// removing the only mode ?
		cursor = NULL;					// list is now empty
	else
		cursor->next = old->next;		// link out the old node
	delete old;							// delete the old node
}

int CircularlyLinkedList()
{
	CircleList playlist;				// []
	playlist.add("Stayin Alive");		// [Stayin Alive]
	playlist.add("le Freak");			// [le Freak, Stayin Alive]
	playlist.add("Jive Talkin");		// [Jive Talkin, le Freak, Stayin Alive]

	playlist.advance();					// [le Freak, Stayin Alive, Jive Talkin]
	playlist.advance();					// [Stayin Alive, Jive Talkin, le Freak]
	playlist.remove();					// [Jive Talkin, le Freak]
	playlist.add("Disco Inferno");		// [Disco Inferno, Jive Talkin, le Freak]
	return EXIT_SUCCESS;
}