#include "Array_Linked_List_Recursion.h"
#include <vector>
#include <cstdlib>

class ExampleDynamicAllocation {
public:
	ExampleDynamicAllocation(const int rows, const int columns);
	~ExampleDynamicAllocation();
private:
	int rows;
	int columns;
	int** tableaux;
};

ExampleDynamicAllocation::ExampleDynamicAllocation(const int rows, const int columns) : rows(rows), columns(columns)
{
	this->tableaux = new int* [this->rows];									// allocate an array of row pointers
	for (int i = 0; i < this->rows; i++)
		this->tableaux[i] = new int[this->columns];							// allocate the i-th rows
}

ExampleDynamicAllocation::~ExampleDynamicAllocation()
{
	for (int i = 0; i < this->rows; i++)
		delete[] tableaux[i];												// delete the i-th row
	delete[] tableaux;														// delete the array of row pointers
}

class TicTacToe {
public:
	TicTacToe() {}
	void clearBoard();
	void putMark(int i, int j);
	bool isWin(int mark) const;
	int getWinner() const;
	void printBoard();
private:
	int X = 1, O = -1, EMPTY = 0;
	int board[3][3];
	int currentPlayer;
};

void TicTacToe::clearBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			this->board[i][j] = EMPTY;
	}
	this->currentPlayer = this->X;
}

void TicTacToe::putMark(int i, int j)
{
	this->board[i][j] = this->currentPlayer;
	this->currentPlayer = -currentPlayer;
}

bool TicTacToe::isWin(int mark) const
{
	int win = 3 * mark; // +3 for X and -3 for O
	return ((board[0][0] + board[0][1] + board[0][2] == win) // row 0
		|| (board[1][0] + board[1][1] + board[1][2] == win) // row 1
		|| (board[2][0] + board[2][1] + board[2][2] == win) // row 2
		|| (board[0][0] + board[1][0] + board[2][0] == win) // column 0
		|| (board[0][1] + board[1][1] + board[2][1] == win) // column 1
		|| (board[0][2] + board[1][2] + board[2][2] == win) // column 2
		|| (board[0][0] + board[1][1] + board[2][2] == win) // diagonal
		|| (board[2][0] + board[1][1] + board[0][2] == win)); // diagonal
}

int TicTacToe::getWinner() const
{
	if (this->isWin(X)) return X;
	else if (this->isWin(O)) return O;
	else return EMPTY;
}

void TicTacToe::printBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			switch (this->board[i][j])
			{
			case 1:
				std::cout << "X";
				break;
			case -1:
				std::cout << "O";
				break;
			case 0:
				std::cout << " ";
				break;
			}
			if (j < 2) std::cout << "|";
		}
		if (i < 2) std::cout << "\n-*-*-*\n";
	}
}


int TwoDimensionalArrays()
{
	// example STL lib vector for 2 dim "recommended"
	std::vector< std::vector<int> > M(5, std::vector<int>(6));
	std::cout << M[0][1] << std::endl;

	// TIC-TAC-TOE
	TicTacToe jeu;
	jeu.clearBoard();
	jeu.putMark(0, 0);
	jeu.putMark(1, 1);
	jeu.putMark(0, 1);
	jeu.putMark(0, 2);
	jeu.putMark(2, 0);
	jeu.putMark(1, 2);
	jeu.putMark(2, 2);
	jeu.putMark(2, 1);
	jeu.putMark(1, 0);
	jeu.printBoard();
	int winner = jeu.getWinner();
	if (winner != 0)
		std::cout << " " << (winner == 1 ? "X" : "O") << " wins" << std::endl;
	else
		std::cout << " Tie" << std::endl;
	return EXIT_SUCCESS;
}
