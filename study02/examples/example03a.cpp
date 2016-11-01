#include <iostream>

void fn(int a)
{
	std::cout << "fn(int)" << std::endl;
}

void fn(int* p)
{
	std::cout << "fn(int*)" << std::endl;
}

int main()
{
	fn(0);
	fn(NULL);

	return 0;
}

