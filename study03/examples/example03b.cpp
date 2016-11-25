#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1 = "Hello, World";
	string str2 = "Hello, Word";

	if (str1 == str2) 
		cout << "Same!" << endl;
	else
		cout << "Different!" << endl;

	str1 = str1 + str2;
	cout << str1 << endl;

	cout << str1.size() << ' ' << str2.length() << endl;

	return 0;

}