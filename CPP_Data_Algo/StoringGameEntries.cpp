#include "Array_Linked_List_Recursion.h"

class GameEntry {											// a game score entry
public:
	GameEntry(const std::string& n = " ", int s = 0);		// constructor
	std::string getName() const;							// get player name
	int getScore() const;									// get score
private:
	std::string name;										// player's name
	int score;												// player's score
};

class IndexOutOfBounds {												// generic run-time exception
public:
	IndexOutOfBounds(const std::string& err) { errorMsg = err; }
	std::string getMessage() const { return errorMsg; }
private:
	std::string errorMsg;
};

class Scores {												// stores game high scores
public:
	Scores(int maxEnt = 10);								// constructor
	~Scores();												// destructor
	void add(const GameEntry& e);							// add a game entry
	GameEntry remote(int i)									// remove the ith entry
		throw(IndexOutOfBounds);
private:
	int maxEntries;											// maximum number of entries
	int numEntries;											// actual number of entries
	GameEntry* entries;										// array of game entries
};

GameEntry::GameEntry(const std::string& n, int s) : name(n), score(s) {}

std::string GameEntry::getName() const { return this->name; }
int GameEntry::getScore() const { return this->score; }

Scores::Scores(int maxEnt)									// constructor
{
	this->maxEntries = maxEnt;								// save the max size
	entries = new GameEntry[this->maxEntries];				// allocate array storage
	this->numEntries = 0;									// initially no elements
}

Scores::~Scores()											// destructor
{
	delete[] entries;
}

void Scores::add(const GameEntry& e)										// add a game entry
{
	int newScore = e.getScore();											// scores to add
	if (this->numEntries == this->maxEntries)								// the array is full
	{
		if (newScore <= this->entries[this->maxEntries - 1].getScore())
			return;															// not high enough - ignore
	}
	else
		this->numEntries++;													// if not full, one more entry

	int i = numEntries - 2;													// start with the next to last
	while (i >= 0 && newScore > this->entries[i].getScore())
	{
		this->entries[i + 1] = this->entries[i];							// shift right if smaller
		i--;
	}
	this->entries[i + 1] = e;												// put e in the empty spot
}

GameEntry Scores::remote(int i) throw(IndexOutOfBounds)
{
	if ((i < 0) || (i >= this->numEntries))									// invalid index
		throw IndexOutOfBounds("Invalid index");
	GameEntry e = entries[i];												// save the removed object
	for (int j = i + 1; j < this->numEntries; j++)
		this->entries[j - 1] = this->entries[j];							// shift entries left
	this->numEntries--;														// one fewer entry
	return e;																// return the removed object
}

int StoringGameEntries()
{
	GameEntry ent("jule1", 1000);
	GameEntry ent2("jule2", 1200);
	GameEntry ent3("jule3", 1300);
	GameEntry ent4("jule4", 1250);
	Scores tableau;
	tableau.add(ent);
	tableau.add(ent2);
	tableau.add(ent3);
	tableau.add(ent4);
	return EXIT_SUCCESS;
}