#include "Array_Linked_List_Recursion.h"

void insertionSort(char* A, int n)				// sort an array of n characters
{
	for (int i = 1; i < n; i++)					// insertion loop
	{
		char cur = A[i];						// current character to insert
		int j = i - 1;							// start at previous character
		while ((j >= 0) && (A[j] > cur))		// while A[j] is out of order
		{
			A[j + 1] = A[j];					// move A[j] right
			j--;								// decrement j
		}
		A[j + 1] = cur;							// this is the proper place for cur
	}
}

int SortingAnArray()
{
	char A[8] = { 'B', 'C', 'D', 'A', 'E', 'H', 'G', 'F'};
	insertionSort(A, 8);
	for (int i = 0; i < 8; i++)
		std::cout << A[i] << " ";
	std::cout << std::endl;
	return EXIT_SUCCESS;
}