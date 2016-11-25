#include <iostream>	

int main()
{
	enum TrafficLight {  RED, YELLOW, GREEN };
	enum Job {  WARRIOR, RANGER, WIZARD };
	enum Coffee { 
		LATTE = 10, MOCHA = 25 
	};

	int jobNum = WARRIOR;
	int i = GREEN + LATTE;

	if (YELLOW == RANGER)
		std::cout << "Same!" << std::endl;
	else
		std::cout << "Different!" << std::endl;
	return 0;
}