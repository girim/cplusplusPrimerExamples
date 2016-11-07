#include <iostream>
#include <type_traits>

int min(int lhs, int rhs)
{
	std::cout << "Non-Template function called ...." << std::endl;
	return lhs < rhs ? lhs : rhs;
}

template<typename T>
T min(T lhs, T rhs)
{
	std::cout << "Template function called...." << std::endl;
	return lhs < rhs ? lhs : rhs;
}

template<typename T1, typename T2>
auto max(T1 lhs, T2 rhs)
{
	std::cout << "max version-1 is called ...." << std::endl;
	return lhs > rhs ? lhs : rhs;
}

template<typename RT, typename T1, typename T2>
RT max(T1 lhs, T2 rhs)
{
	std::cout << "max version-2 is called ...." << std::endl;
	return lhs > rhs ? lhs : rhs;
}

int main(int argc, char const *argv[])
{
	std::cout << "min{int, int}: " << ::min(2,4) << std::endl;
	std::cout << "min{char, char}: " << ::min('a','g') << std::endl;
	std::cout << "min{double, double}: " << ::min(1.2, 3.4) << std::endl;

	std::cout << "min{char, int}: " << ::min('g', 4) << std::endl;
	/*Explicity calling template function*/
	std::cout << "min<>{int, int}: " << ::min<>(5, 6) << std::endl;
	std::cout << "min<double>{double, double}: " << ::min<double>(2,4) << std::endl;

	std::cout << "max{int, double}: " << ::max(4, 9.2) << std::endl;
	std::cout << "max long double{int, double}: " << ::max<long double>(6, 7.3) << std::endl;
	
	//std::cout << "max{int, double}: " << ::max<int>(4, 9.2) << std::endl;

	return 0;
}