#include <iostream>
#include <typeinfo>

template<typename T>  //Template parameters
T max(T lhs, T rhs)   //Call parameters
{
	std::cout << "Type is: " << typeid(T).name() << std::endl; 
	/*std::cout << "Adds lhs: " << lhs << std::endl;
	std::cout << "Adds rhs: " << rhs << std::endl;*/
	//*lhs =20;
	return lhs > rhs ? lhs : rhs;
}

int main(int argc, char const *argv[])
{
	std::cout << "max{int, int}: " << ::max(1,2) << std::endl;
	/*T will be deduced automatically to 'int'*/

	std::cout << "max{double, double}: " << ::max(1.2, 3.4) << std::endl;
	/*T will be deduced automatically to 'double'*/

	std::cout << "max{char, char}: " << ::max('a', 'g') << std::endl;
	/*T will be deduced automatically to 'char' */

	/*Since we are passing arguments by 'value' 
	1. Qualifiers 'const' and 'volatile' are ignored 
	2. References are deduced to referenced type
	3. Raw arrays will be converted to pointers
	4. functions will be converted to pointer-to-function*/
	const int lhs = 22;
	const int rhs = 44;
	std::cout << "max{lhs, rhs}: " << ::max(lhs, rhs) << std::endl;

	const int &refToLhs = lhs;
	const int &refToRhs = rhs;
	std::cout << "max{refToLhs, refToRhs}: " << ::max(refToLhs, refToRhs) << std::endl;

	const int *ptrToLhs = &lhs;
	const int *ptrToRhs = &rhs;
	std::cout << "Address of ptrToLhs: " << &lhs << std::endl;
	std::cout << "Address of ptrToRhs: " << &rhs << std::endl;
	std::cout << "max{ptrToLhs, ptrToRhs}: " << ::max(ptrToLhs, ptrToRhs) << std::endl;
	/*Type will be deduced as 'pointer to const int' */

	double numbers[] = {1.1,2.2,3.3};
	double number =  4.4;
	std::cout << "max{numbers[], number}: " << ::max(numbers, &number) << std::endl;

	/*Passing different Types for same template parameter 'T'*/
	std::cout << "max{int, double}: " << ::max(static_cast<double>(4), 4.5) << std::endl;
	std::cout << "max{int, double}: " << ::max<int>(4, 4.5) << std::endl;

	return 0;
}