# 1st study

## INPUT / OUTPUT METHOD
- 헤더 파일의 변화:
	- `stdio.h` -> `iostream`
- 입출력 함수의 변화
	- 출력: `	printf` -> `std::cout`
		- `cout`은 삽입 연산자 `<<` 를 사용해 무언가를 console 화면에 출력
	- 입력: `scanf` -> `std::cin 
		- `cin`은 삽입 연산자 `>>` 를 사용해 console로 부터 무언가를 저장
	- `<<` 나 `>>` 를 화살표 방향이라고 생각하면 쉽게 이해 가능
	- 입력이나 출력 형식을 지정하지 않고 사용 (*i.e.* `%d`, `%c`, etc.)
- 예제#1a:
	- C:
	```c
	#include <stdio.h>
	int main() 
	{
		printf("Hello, World!");
		return 0;
	}
	```
	- C++:
	```cpp
	#include <iostream>
	int main() 
	{
		std::cout << "Hello, World!";
		return 0;
	}
	```
- 예제#1b:
	- C:
	```c
	#include <stdio.h>
	int main() 
	{
		int x=0;
		printf("Input the number: ");
		scanf("%d", &x);

		printf("x = %d", x);

		return 0;
	}
	```
	- C++:
	```cpp
	#include <iostream>
	int main() 
	{
		int x=0;

		std::cout << "Input the number: ";
		std::cin >> x;

		std::cout << "x = " << x << std::endl;

		return 0;
	}
	```

## BOOL TYPE
- C에서는 조건문(if statement)의 참/거짓 을 표현하기 위해 `int`를 사용
	- 참(true): 0을 제외한 모든 값
	- 거짓(false): 0
- C++에서는 참/거짓을 명확하게 사용하기 위해 `bool`이라는 타입이 추가됨
	- 참(true): `true`
	- 거짓(false): `false`
- 예제#2a:
	- C:
	```c
	#include <stdio.h>
	int main() 
	{
		int i=1;

		if (i)
			printf("i is true!\n");
		else
			printf("i is false!\n");
		return 0;
	}
	```
	- C++:
	```cpp
	#include <iostream>
	int main() 
	{
		bool b = true;

		if (b)
			std::cout << "b is true!" << std::endl;
		else
			std::cout << "b is false!" << std::endl;
		return 0;
	}
	```
- 예제#2b:
	- C++:
	```cpp
	#include <iostream>

	int main()
	{
		bool b = true;

		std::cout << b << std::endL;
		std::cout << !b << std::endL;
	}
	```
- 예제#2c:
	- C++:
	```cpp
	#include <iostream>

	int main()
	{
		bool b = true;

		std::cout.setf(std::ios::boolalpha);
		std::cout << b << std::endL;
		std::cout << !b << std::endL;

		std::cout.unsetf(std::ios::boolalpha);
		std::cout << b << std::endL;
		std::cout << !b << std::endL;
	}
	```


