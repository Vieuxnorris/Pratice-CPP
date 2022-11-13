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