# study03

## SCOPED ENUM
- C/C++에서 기존에 사용하던 열거형에 존재하는 문제들
	- A 열거체에서 사용한 T라는 이름을 B 열거체에서 사용할 수 없음
		- 전역(Global) 범위로 선언되기 때문
	- 서로 다른 열거체 변수끼리 더하거나 비교할 수 있음
		- 기본적으로 열거체의 타입은 int (묵시적으로 변환되기 때문)
- C++11에는 이런 문제들을 보완한 범위 지정 열거체를 제공
	- `enum` 대신 `enum class`를 사용
	- 명시적으로 타입을 지정하지 않으면 오류 (묵시적 변환 X)
	- 서로 다른 열거체 변수끼리 연산할 수 없음

## EXAMPLE: SCOPED ENUM
- ### 예제#01a:
	- [C/C++98][ex01a]:
	```cpp
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
	```
	- [C++11][ex01b]:
	```cpp
	#include <iostream>	

	int main()
	{
		enum TrafficLight {  RED, YELLOW, GREEN };
		enum Job {  WARRIOR, RANGER, WIZARD };
		enum Coffee { 
			LATTE = 10, MOCHA = 25 
		};

		int jobNum = Job::WARRIOR;
		int i = static_cast<int>(TrafficLight::GREEN) 
			+ static_cast<int>(Coffee::LATTE);

		if (TrafficLight::YELLOW == Job::RANGER)
			std::cout << "Same!" << std::endl;
		else
			std::cout << "Different!" << std::endl;
		return 0;
	}
	```

## BINARY LITERAL, SEPARATOR
- C/C++에서는 10진수 외에 8진수, 16진수를 표현할 수 있음
	- __8진수__:
	- __16진수__:
	- 하지만 2진수를 표현하는 방법은 없었음.
- C++14에서 2진수를 표현할 수 있는 방법 추가!: `0b~`
- 또한, 기존 C/C++에서는 큰 숫자를 읽기 힘듬
	- *__ex__*: `int INT_MAX = 2147483647;`
- C++14에는 구분자가 추가되어 큰 숫자를 읽기 쉬워짐
	- *__ex__*: `int INT_MAX = 21'4748'3647;`


## EXAMPLE: BINARY LITERAL, SEPARATOR
- ### 예제02:
	- [C++14][ex02a]:
	```cpp
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
	```


## `std::string`
- C에서는 문자열을 나타내기 위해 `char[]`나 `char*`를 사용
	- 하지만 비교, 연결, 길이 등 문자열 관련 함수들을 사용할 때 불편함
		- __비교__: `strcmp`,
		- __연결__: `strcat`,
		- __길이__: `strlen`
- C++에서는 `std::string`을 사용해 문자열을 나타냄
	- 먼저, `<string>`헤더 파일 포함: `#include <string>`
	- `std::string str = "Hello, World;"`
	- 비교, 연결, 길이 등의 문자열 동작들을 편리한 방법으로 제공
		- __비교__: `==`,
		- __연결__: `+`,
		- __길이__: `size()` or `length()`
	- 참조: [http://en.cppreference.com/w/cpp/string/basic_string][link01]


## EXAMPLE: `std::string`
- ### 예제03:
	- [C][ex03a]:
	```c
	#include <stdio.h>

	int main()
	{
		char str1[30] = "Hello, World";
		char* str2 = "Hello, Word";

		if (strcmp(str1, str2) == 0) {  printf("Same!\n");  }
		else printf("Different!\n");

		strcat(str1, str2);
		printf("%s\n", str1);

		printf("%d, %d\n", strlen(str1), strlen(str2));

		return 0;
	}
	```
	- [C++][ex03b]:
	```cpp
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
	```


[ex01a]: https://github.com/chanhi2000/moderncpp/blob/study03/study03/examples/example01a.cpp
[ex01b]: https://github.com/chanhi2000/moderncpp/blob/study03/study03/examples/example01b.cpp
[ex02a]: https://github.com/chanhi2000/moderncpp/blob/study03/study03/examples/example02a.cpp
[ex03a]: https://github.com/chanhi2000/moderncpp/blob/study03/study03/examples/example03a.c
[ex03b]: https://github.com/chanhi2000/moderncpp/blob/study03/study03/examples/example03b.cpp

[link01]: http://en.cppreference.com/w/cpp/string/basic_string





