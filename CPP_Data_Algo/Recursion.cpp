#include "Array_Linked_List_Recursion.h"
#include <vector>

int recursiveFatorial(int n)						// recursive factorial function
{
	if (n == 0)										// basic case
		return 1;
	else
		return n * recursiveFatorial(n - 1);		// recursive case
}

int BinaryFib(int k)
{
	if (k <= 1)
		return k;
	else
		return BinaryFib(k - 1) + BinaryFib(k - 2);
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

int BinarySum(int A[], int i, int n)
{
	if (n == 1)
		return A[i];
	return BinarySum(A, i, (n / 2)) + BinarySum(A, i + (n / 2), (n / 2));
}

int ReverseArray(int A[], int i, int j)
{
	if (i < j)
	{
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
		ReverseArray(A, i + 1, j - 1);
	}
	return 0;
}

int IterativeReverseArray(int A[], int i, int j)
{
	while (i < j)
	{
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
		i += 1;
		j -= 1;
	}
	return 0;
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
	std::cout << LinearSum(A, 4) << std::endl;
	std::cout << ReverseArray(A, 0, 3) << std::endl;
	std::cout << BinarySum(A, 0, 4) << std::endl;
	return EXIT_SUCCESS;
}