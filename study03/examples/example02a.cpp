#include <iostream>	

int main()
{
	int decimal = 52;
	int octal = 064;
	int hexadecimal = 0x34;
	int binary = 0b110100; //C++14

	int maxInt_Cpp98 = 2147483647;
	// int maxInt_Cpp14 = 21'4748'3647;	//C++14

	std::cout << binary << std::endl;

	return 0;
}