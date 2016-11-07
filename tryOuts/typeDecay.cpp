#include <iostream>
#include <typeinfo>
#include <type_traits>

void testFunction(int integer, double floating)
{
	std::cout << "Type of integer: " << typeid(integer).name() << std::endl; 
	std::cout << "Type of floating: " << typeid(floating).name() << std::endl; 

	std::cout << "Value of integer: " << integer << std::endl;
	std::cout << "Value of floating: " << floating << std::endl;
}

void functionAcceptsArrays(int *ptr, int ptr2[])
{
	std::cout << "ptr value is: " << *ptr++ << std::endl;
	std::cout << "ptr value is: " << *ptr++ << std::endl;
	std::cout << "ptr value is: " << *ptr2++ << std::endl;
	std::cout << "ptr value is: " << *ptr2++ << std::endl;
}

void acceptFunc(void(*pf)(int, double))
{
	pf(4,5);
}

int main(int argc, char const *argv[])
{
	testFunction(10, 30.30);

	void (*pf)(int, double) = testFunction;
	pf(1,1);
	acceptFunc(testFunction);

	/*const will be decayed to thier respective types*/
	const int var1 = 20;    
	const double var2 = 30.3;
	testFunction(var1, var2);

	const int &refToVar1 = var1;
	const double &refToVar2 = var2;
	testFunction(refToVar1, refToVar2);

	int arry[] = {1,2,3,4};
	functionAcceptsArrays(arry,arry);

	/*Initialization of 'auto' always decays*/
	int var = 12;
	const int &ref = var;
	auto decayedVar = var;

	std::cout << "type of ref: " << typeid(ref).name() << std::endl;
	std::cout << "type of decayedVar: " << typeid(ref).name() << std::endl;

	return 0;
}