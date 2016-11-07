#include <iostream>
#include <string>
#include <typeinfo>

template <typename T>
T max(T lhs, T rhs)
{
	std::cout <<"Type of T(copy): " << typeid(T).name() << std::endl;
	return lhs > rhs ? lhs : rhs;
}

template <typename T>
const T& max_2(const T& lhs, const T& rhs)
{
	//std::cout <<"Type of T: " << typeid(T).name() << std::endl;
	return lhs > rhs ? lhs : rhs; 
}

int main(int argc, char const *argv[])
{
	std::cout << "max(1,6) is: " << ::max(1,6) << std::endl;
	double first = 1.23245, second = 1.23244;
	std::cout << "max(first,second): " << ::max(first,second) << std::endl;

	std::string firstStr = "mathematics", secondStr = "math";
	std::cout << "max(firstStr, secondStr): " << ::max(firstStr,secondStr) << std::endl;

	int const var1 = 10;
	int var2 = 20;
	std::cout << "type: " << typeid(var1).name() << std::endl;

	/*the below call to max, T will be deduced to 'int' ignoring 'const' as we are
		passing params by copying*/
	std::cout << "max(var1, var2): " << ::max(var1, var2) << std::endl;

	int var3 = 30;
	int &ref1 = var3;
	int &ref2 = var2;
	/*References will be deduced to reference types, i.e 'int' here not 'int&'*/
	std::cout << "max(ref, var2): " << ::max(ref1, ref2) << std::endl;

	/*Raw array or function types are converted to corresponding pointer types*/
	int array[] = {4};
	std::cout << "max(array, var2): " << ::max(array, &var2) << std::endl;

	max_2(var1, var2);

	//std::cout <<"Using Automatic type Deduction: " << ::max(4,4.9) << std::endl;
	std::cout <<"Using Explicit type Deduction: " << ::max<double>(4,4.9) << std::endl;

	return 0;
}