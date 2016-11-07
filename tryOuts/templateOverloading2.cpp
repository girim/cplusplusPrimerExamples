#include <iostream>
#include <typeinfo>
#include <cstring>

/*Template overloaded function*/
template<typename T>
T max (T lhs, T rhs)
{
	std::cout << "version-1 " << __func__ << " called...." << std::endl;
	return lhs > rhs ? lhs : rhs;
}

template<typename T>
T* max(T* lhs, T* rhs)
{
	std::cout << "version-2 " << __func__ << " called...." << std::endl;
	return *lhs > *rhs ? lhs : rhs;
}

/*Non-Template overloaded function*/
const char* max(const char *lhs, const char *rhs)
{
	std::cout << "version-3 " << __func__ << " called...." << std::endl;
	return std::strcmp(rhs, lhs) ? lhs : rhs;
} 

int stringCmp()
{
	const char* strOne = "Hello";
	const char* strTwo = "Hi";
	int ret = 0;

	while( *strOne != '\0')
	{
		if(*strTwo != '\0' && (*strOne == *strTwo))
		{
			strOne++;
			strTwo++;
		}
		else if (*strOne < *strTwo)
		{
			std::cout << "else if: " << *strOne << " " << *strTwo << std::endl;
			ret = -1;
			return ret;
		}
		else
		{
			std::cout << "else : " << *strOne << " " << *strTwo << std::endl;
			ret = 1;
			return ret;
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	int number1 = 1, number2 = 3;
	std::cout << "max{int, int}: " << ::max(number1, number2) << std::endl;

	const std::string stringOne = "hello";
	const std::string stringTwo = "hi";
	std::cout << "max{char, char}: " << ::max(stringOne, stringTwo) << std::endl;

	std::cout << "max{char, char}: " << ::max("hello", "hi") << std::endl;

	int *ptrToNumber1 = &number1;
	int *ptrToNumber2 = &number2;
	std::cout << "max{*ptr, *ptr}: " << *(::max(ptrToNumber1, ptrToNumber2)) << std::endl;

	const char *strOne = "hello";
	/*Reference to the pointer*/
	const char *&ref = strOne;

	while (*ref != '\0')
		std::cout << *ref++ << std::endl;

	std::cout << "Reference to pointer: " << strOne << std::endl;
	std::cout << stringCmp() << std::endl;
	return 0;

}