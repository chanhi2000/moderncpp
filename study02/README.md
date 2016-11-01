# study02

## RANGE-BASED `for`
- 반복문 중 가장 많이 사용되는 `for` 문은 지정된 횟수 만큼 반복하는 작업에도 사용되지만 배열(array)이나 각종 container에 있는 각 요소들에 무언가를 수행하기 위해 순회하는 목적으로도 많이 사용함.
- 하지만, 조건문에 배열(array)이나 container에 몇 개의 요소가 들어있는지 명시해야된다는 단점이 존재함!
- 요소들의 개수에 상관없이 반복문을 수행할 수 없을까?
	- 범위 기반 `for`문의 등장!

## EXAMPLE:
- 예제#01a:
	- C/C++98:
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
- 예제#01b:
	- python:
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
- 예제#02a:
	- C:
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
	- C++:
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
	- C++:
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
- 예제#03a:
	- C++98:
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
	- C++11:
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
- 예제#03b:
	- C++11:
	```cpp
	#include <iostream>

	int main()
	{
		std::cout << sizeof(nullptr) << std::endl;

		std::cout << typeid(nullptr).name() << std::endl;

		return 0;
	}
	```
- 예제#03c:
	- C++98:
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
	- C++11:
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

	








