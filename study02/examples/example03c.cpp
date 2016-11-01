#include <iostream>

int main()
{
	int* p1 = new int;
	delete p1;
	p1 = NULL;
	//p1 = nullptr; //C++11

	int* p2 = new int[10];
	delete[] p2;
	p2 = NULL;
	// p2 = nullptr; //C++11

	return 0;
}