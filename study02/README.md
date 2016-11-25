# study02

## RANGE-BASED `for`
- 반복문 중 가장 많이 사용되는 `for` 문은 지정된 횟수 만큼 반복하는 작업에도 사용되지만 배열(array)이나 각종 container에 있는 각 요소들에 무언가를 수행하기 위해 순회하는 목적으로도 많이 사용함.
- 하지만, 조건문에 배열(array)이나 container에 몇 개의 요소가 들어있는지 명시해야된다는 단점이 존재함!
- 요소들의 개수에 상관없이 반복문을 수행할 수 없을까?
	- 범위 기반 `for`문의 등장!

## EXAMPLE:
- ### 예제#01a:
	- [C/C++98][ex01a]:
	```cpp
	#include <iostream>

	int main()
	{
		int arr[] = {1,2,3,4,5};

		for (int i=0; i<5; ++i)
			std::cout << arr[i] << std::endl;

		return 0;
	}
	```
	- C++11:
	```cpp
	#include <iostream>

	int main()
	{
		int arr[] = {1,2,3,4,5};

		for (auto& i: arr)
			std::cout << i << std::endl;

		return 0;
	}
	```
- ### 예제#01b:
	- [python][ex01b]:
	```python
	def mean(seq):
		n = 0.0

		for x in seq:
			n += x
		return n / len(seq)

	```
	- C++11:
	```cpp
	auto mean(const Sequence& seq)
	{
		
		auto n =0.0;

		for (auto& x:seq)
			n+= x;

		return n / seq.size();
	}
	```

## MEMORY ALLOCATION/DE-ALLOCATION
- C에서는 동적 메모리 할당(dynamic memory allocation)을 위해 `malloc`, `calloc`등을 사용. 또한 동적 메모리 반환(dynamic memory de-allocation)을 위해 `free`를 사용.
- C++에서는  `malloc`, `calloc`등을 대신해 `new`를 사용하고 `free`를 대신해 `delete`을 사용
- __주의해야 할 점__: `new`는 `delete로, `new[]`는 `delete[]`로
	- 단일 객체에 대한 동적 메모리
		- 할당: `new`
		- 반환: `delete`
	- 배열 객체에 대한 동적 메모리
		- 할당: `new[]`
		- 반환: `delete[]`

## EXAMPLE: MEM ALLOC/DEALLOC
- ### 예제#02a:
	- [C][ex02a(1)]:
	```c
	int main()
	{
		int i;
		int** arr = (int**)malloc(sizeof(int*) * 5);
		for (i=0; i<5; ++i)
			arr[i] = (int*)malloc(sizeof(int) * 5);

		// ...

		for (i=0; i<5; ++i)
			free(arr[i]);
		free(arr);
		arr = NULL;

		return 0;
	}
	```
	- [C++][ex02a(2)]:
	```cpp
	int main()
	{
		int** arr = new int*[5];
		for (int i=0; i<5; ++i)
			arr[i] = new int[5];

		// ...

		for (int i=0; i<5; ++i)
			delete[] arr[i];
		delete[] arr;
		arr = NULL;

		return 0;
	}
	```
- ### 예제#02b:
	- [C++][ex02b]:
	```cpp
	int main()
	{
		int* p1 = new int;
		delete p1;
		p1 = NULL;

		int* p2 = new int[10];
		delete[] p2;
		p2 = NULL;
	
		return 0;
	}
	```


## NULL POINTER
- C에서 `NULL` pointer를 나타내기 위해 NULL이나 상수(constant) 0를 사용
- 하지만, `NULL`은 진짜 `NULL` pointer를 가리킬까?
	- `#define NULL 0`, 따라서 NULL = 0
- `NULL`이나 상수(constant) 0을 사용해 함수에 인자로 넘기는 경우, `int`타입으로 추론되는 문제 발생
	- `nullptr` 키워드의 등장!
- 포인터 변수와 마찬가지로, 크기는 4 byte
- __주의할 점__: `nullptr`은 type이 아니다!
	- `nullptr`은 NULL pointer literal, 실제 type은 `std::nulptr_t`


## EXAMPLE: NULL POINTEER
- ### 예제#03a:
	- [C++98][ex03a]:
	```cpp
	#include <iostream>
	#define NULL 0

	void f(int a)
	{
		std::cout << "f(int)" << std::endl;
	}

	void f(int* p)
	{
		std::cout << "f(int*)" << std::endl;
	}

	int main()
	{
		f(0);
		f(NULL);

		return 0;
	}
	```
	- [C++11][ex03a]:
	```cpp
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
		fn(nullptr);

		return 0;
	}
	```
- ### 예제#03b:
	- [C++11][ex03b]:
	```cpp
	#include <iostream>

	int main()
	{
		std::cout << sizeof(nullptr) << std::endl;

		std::cout << typeid(nullptr).name() << std::endl;

		return 0;
	}
	```
- ### 예제#03c:
	- [C++98][ex03c]:
	```cpp
	#include <iostream>

	int main()
	{
		int* p1 = new int;
		delete p1;
		p1 = NULL;

		int* p2 = new int[10];
		delete[] p2;
		p2 = NULL;

		return 0;
	}
	```
	- [C++11][ex03c]:
	```cpp
	#include <iostream>

	int main()
	{
		int* p1 = new int;
		delete p1;
		p1 = nullptr;

		int* p2 = new int[10];
		delete[] p2;
		p2 = nullptr;

		return 0;
	}
	```


## `static_cast`
- C에서는 ()를 통해 명시적 캐스팅 (Explicit Casting)을 할 수 있음.
- C의 명시적 캐스팅은 개발자의 실수를 그대로 용납하기 때문에 차후에 오류가 생길 가능성이 있음.
- C++에서는 좀 더 명시적인 캐스팅 방법을 통해 개발자가 캐스팅의 목적을 명확하게 명시함으로써 개발자의 의도를 컴파일러에게 전달하며 오류를 방지함.
	- *__ex__*: `static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast`
	- `_cast-name<type>(표현식);`

- __`static_cast`__: `const`를 제외한 모든 명확한 타입 변환에 사용
	- [http://en.cppreference.com/w/cpp/language/static_cast][link01]
- __`dynamic_cast`__: 기본 타입에 대한 포인터나 참조자를 파생 타입에 대한 포인터나 참조자로 안전하게 변환
	- [http://en.cppreference.com/w/cpp/language/dynamic_cast][link02]
- __`const_cast`__: `const` 객체를 `const`가 아닌 타입으로 변환
	- [http://en.cppreference.com/w/cpp/language/const_cast][link03]
- __`reinterpret_cast`__: 비트 구성 형식을 저수준에서 재해석
	- [http://en.cppreference.com/w/cpp/language/reinterpret_cast][link04]


## EXAMPLE: `static_cast`
- ### 예제#04a:
	- [C++98][ex04a]:
	```cpp
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
	```




[ex01a]: https://github.com/chanhi2000/moderncpp/blob/study02/study02/examples/example01a.cpp
[ex01b]: https://github.com/chanhi2000/moderncpp/blob/study02/study02/examples/example01b.py
[ex02a(1)]: https://github.com/chanhi2000/moderncpp/blob/study02/study02/examples/example02a.c
[ex02a(2)]: https://github.com/chanhi2000/moderncpp/blob/study02/study02/examples/example02a.cpp
[ex02b]: https://github.com/chanhi2000/moderncpp/blob/study02/study02/examples/example02b.cpp
[ex03a]: https://github.com/chanhi2000/moderncpp/blob/study02/study02/examples/example03a.cpp
[ex03b]: https://github.com/chanhi2000/moderncpp/blob/study02/study02/examples/example03b.cpp
[ex03c]: https://github.com/chanhi2000/moderncpp/blob/study02/study02/examples/example03c.cpp
[ex04a]: https://github.com/chanhi2000/moderncpp/blob/study02/study02/examples/example04a.cpp


[link01]: http://en.cppreference.com/w/cpp/language/static_cast
[link02]: http://en.cppreference.com/w/cpp/language/dynamic_cast
[link03]: http://en.cppreference.com/w/cpp/language/const_cast
[link04]: http://en.cppreference.com/w/cpp/language/reinterpret_cast







