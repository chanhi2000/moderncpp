#include <iostream>

int main()
{
	// allocation
	int** arr = new int*[5];
	for (int i=0; i<5; ++i)
		arr[i] = new int[5];

	/*
	 * array activity
	 */

	// deallocation
	for (int i=0; i<5; ++i)
		delete[] arr[i];
	delete[] arr;
	arr = NULL;

	return 0;
}