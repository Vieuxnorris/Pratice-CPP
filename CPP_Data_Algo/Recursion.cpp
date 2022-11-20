#include "Array_Linked_List_Recursion.h"

int recursiveFatorial(int n)						// recursive factorial function
{
	if (n == 0)										// basic case
		return 1;
	else
		return n * recursiveFatorial(n - 1);		// recursive case
}

void drawOneTick(int tickLength, int ticklabel = -1)
{
	for (int i = 0; i < tickLength; i++)
		std::cout << "-";
	if (tickLength >= 0)
		std::cout << " " << tickLength;
	std::cout << "\n";
}

void drawTicks(int tickLength)
{
	if (tickLength > 0)
	{
		drawTicks(tickLength - 1);
		drawOneTick(tickLength);
		drawTicks(tickLength - 1);
	}
}

int LinearSum(int A[], int n)
{
	if (n == 1)
		return A[0];
	else
		return LinearSum(A, n - 1) + A[n - 1];
}

void drawRuler(int nInches, int majorLength)
{
	drawOneTick(majorLength, 0);
	for (int i = 1; i <= nInches; i++)
	{
		drawTicks(majorLength - 1);
		drawOneTick(majorLength, i);
	}
}

int Recursion()
{
	int A[4] = { 1,2,3,4};
	//std::cout << recursiveFatorial(4) << std::endl;
	drawTicks(3);
	std::cout << LinearSum(A, 4);
	return EXIT_SUCCESS;
}