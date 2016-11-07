#include <iostream>
#include <typeinfo>
#include <type_traits>

/*Function template taking multiple parameters*/
template<typename T1, typename T2>
T1 max(T1 lhs, T2 rhs)
{
	return lhs > rhs ? lhs : rhs;
}

template<typename T1, typename T2, typename RT>
RT maxOfTwo(T1 lhs, T2 rhs)
{
	return lhs > rhs ? lhs : rhs;
}

template<typename RT, typename T1, typename T2>
RT maxOfTwoProper(T1 lhs, T2 rhs)
{
	return lhs > rhs ? lhs : rhs;
}

/*Below code works only with C++14 onwords*/
template<typename T1, typename T2>
auto maxWithAuto(T1 lhs, T2 rhs)
{
	return lhs > rhs ? lhs : rhs;
}

/*Return type deduction in c++11*/
template<typename T1, typename T2>
auto maxWithCpp11(T1 a, T2 b)-> typename std::decay<decltype(true?a:b)>::type
/*decay is used to return decayed type, bcoz some times T can be reference type*/
{
	return a > b ? a : b;
}

template<typename T1, typename T2>
/*For c++11 we should write below line as, typename std::common_type<T1, T2>*/
std::common_type_t<T1, T2> maxWithCommonType(T1 lhs, T2 rhs)
{
	return lhs > rhs ? lhs : rhs;
}

/*Default Template Argument Deduction*/
template<typename T1, typename T2, 
			typename RT = std::decay_t<decltype(true? T1() : T2())>>
RT maxWithDefaultRT(T1 lhs, T2 rhs)
{
	return lhs > rhs ? lhs : rhs;
}

template<typename T1, typename T2,
			typename RT = std::common_type_t<T1, T2>>
RT maxWithDefaultRTCommonType(T1 lhs, T2 rhs)
{
	return lhs > rhs ? lhs : rhs;
}

int main(int argc, char const *argv[])
{
	std::cout << "max{int, double}: " << ::max(1, 1.22) << std::endl;
	/*T1 will be deduced to 'int' so return type will be 'int'*/

	std::cout << "max{double, int}: " << ::max(1.22, 1) << std::endl;
	/*T1 will be deduced to 'double' so return type will be 'double' */

	std::cout << "max{int, char}: " << ::max(4, 'g') << std::endl;
	/*T1 will be deduced to 'int' so return type will be 'int' */

	std::cout << "max{char, int}: " << ::max('g', 114) << std::endl;
	/*T1 will be deduced to 'char' so return type will be 'char' */

	std::cout << "maxOfTwo{int, double, double}: " << ::maxOfTwo<int, double, double>(4, 1.23) << std::endl;
	std::cout << "maxOfTwo{int, double, double}: " << ::maxOfTwoProper<int>(4.3, 1.23) << std::endl;

	std::cout << "maxWithAuto{int, double}: " << typeid(::maxWithAuto(3, 1.34)).name() << std::endl;
	std::cout << "maxWithAuto{int, char}: "   << typeid(::maxWithAuto(3, 'a')).name() << std::endl;
	std::cout << "maxWithAuto{int, char}: "   << ::maxWithAuto(3, 'a') << std::endl;

	std::cout << "Sizeof char: " << sizeof(char) << std::endl;
	std::cout << "Sizeof int: " << sizeof(int) << std::endl;
	std::cout << "Sizeof double: " << sizeof(double) << std::endl;

	std::cout << "maxWithCpp11{int, double}: " << typeid(maxWithCpp11(4.66, 12)).name() << std::endl;
	std::cout << "maxWithCommonType{int, double}: " << typeid(maxWithCommonType(18, 1.0)).name() << std::endl;
	std::cout << "maxWithCommonType{int, char}: " << typeid(maxWithCommonType(1, 'a')).name() << std::endl;

	/*Setting default value for RT we can call functions without specifying 'return type' explicitly*/
	std::cout << "maxWithDefaultRT{char, double}: " << typeid(maxWithDefaultRT('g', 9.6)).name() << std::endl;
	std::cout << "maxWithDefaultRTCommonType{int, char}: " << typeid(maxWithDefaultRTCommonType(1, 4.5)).name() << std::endl;
	return 0;
}
