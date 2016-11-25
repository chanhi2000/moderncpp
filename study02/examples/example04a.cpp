#include <iostream>

int main()
{
	char* str = "Hello, World";
		
	/*
	 * SEG FAULT
	 */
	// int* pi = (int*)str;
	// char* pc = (char*)*pi;
	// std::cout << pc << std::endl;
		
	/*
	 * CASTING ERROR
	 */
	int* pi1 = static_cast<int*>(str);
	char* pc1 = static_cast<char*>(*pi1); 
	std::cout << pc1 << std::endl;

	return 0;
}