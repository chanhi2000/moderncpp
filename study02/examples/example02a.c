#include <stdio.h>
#include <stdlib.h> // for memory allocation

int main()
{
	int i;
	// allocation
	int** arr = (int**)malloc(sizeof(int*) * 5);
	for (i=0; i<5; ++i)
		arr[i] = (int*)malloc(sizeof(int) * 5);

	/*
	 * array activity
	 */

	// dealloation
	for (i=0; i<5; ++i)
		free(arr[i]);
	free(arr);
	arr = NULL;

	return 0;
}