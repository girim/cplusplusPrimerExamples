#include <iostream>
#include <typeinfo>
#include <utility>

template<typename T> 
T square(const T& x)
{
	return x * x;
}

template<>
char square(const char& ch)
{
	return ch;
}

//Templates with multiple parameters
template<typename T, typename U>
std::pair<T, U> squareAndCube(const T& numberToSquare, const U& numberToCube)
{
	std::pair<T, U> result;
	result.first = numberToSquare * numberToSquare;
	result.second = numberToCube * numberToCube * numberToCube;

	return result;
}

//Non-type template parameters
template<typename T, int count>
void loopIt(T element)
{
	T value[count];
	for(int index = 0; index < count; index++)
	{
		value[index] = element++;
	}

	std::cout << std::endl;
	for(T val: value)
	{
		std::cout << "Value is: " << val << std::endl;
	}
}

//Specify a default type parameter and default non-type parameter:
template<typename T = float, int count = 4>
T multIt(T value)
{
	for(int index = 0; index < count; index++)
	{
		value = value * value;
	}

	return value;
}


int main()
{
	std::cout << "Square of (4) is: " << typeid(square(4)).name() << std::endl;
	std::cout << "Square of (112121212.234) is: " << typeid(square(1.234)).name() << std::endl;

	float fNumber = 1.1;
	std::cout << "Square of (1.1) is : " << typeid(square(fNumber)).name() << std::endl;
	std::cout << "Square of char(g) is: " << square('G') << std::endl;

	auto result =  squareAndCube(10, 1.1);
	std::cout << "SquareAndCube of: (10, 2.3) is : " << result.first << result.second << std::endl;

	loopIt<int, 4>(10);
	loopIt<float, 6>(1.0);
	loopIt<char, 4>('g');

	std::cout << "multIt using default parameters<float>: " << multIt<>(1.2) << std::endl;
	std::cout << "multIt using default parameters<float>: " << multIt(1.2) << std::endl;
	std::cout << "multIt using default parameters<int>: " << multIt<int, 6>(13) << std::endl;
	std::cout << "multIt using default parameters<int>: " << multIt<int>(13) << std::endl;
	std::cout << "multIt using default parameters<int>: " << multIt<>(2) << std::endl;
	
	return 0;
}

