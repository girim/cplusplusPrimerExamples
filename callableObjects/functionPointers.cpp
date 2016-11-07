#include <iostream>
#include <functional>

int add(int lhs, int rhs)
{
	return lhs + rhs;
}

int substract(int lhs, int rhs)
{
	return (lhs > rhs) ? (lhs - rhs) : (rhs - lhs);
}

double divide(double numerator, double denominator)
{
	return (numerator / denominator);
}

float multiply(float lhs, float rhs)
{
	return lhs * rhs;
}

void testFunctionAdd(int (*fp)(int,int))
{
    std::cout <<"Inside testFunctionAdd: " << fp(1,1) << std::endl;
}

void testFunctionSubstract(int (*fp)(int, int))
{
	std::cout <<"Inside testFunctionSubstract: " << fp(4,2) << std::endl;
}

void testFunctionDivide(double (*fp)(double, double))
{
	std::cout <<"Inside testFunctionDivide: " << fp(4,9) << std::endl;
}

void testFuntionMultiply(float (*fp) (float, float))
{
	std::cout <<"Inside testFuntionMultiply: " << fp(8,10) << std::endl;
}

int main()
{
	//Pointer to Function, <returnType> (*pointerName) (ParameterTypesList)
	int (*functionPointerToAdd) (int , int) = add;
	std::cout <<"Calling function pointer to add: " << functionPointerToAdd(10,20) << std::endl;

	int (*functionPointerToSubstract)(int, int) = substract;
	std::cout <<"Calling function pointer to substract: " << functionPointerToSubstract(30,40) << std::endl;

	double (*functionPointerToDivide)(double, double) = divide;
	std::cout <<"Calling function pointer to divide: " << functionPointerToDivide(50,60) << std::endl;

	float (*functionPointerToMutliply)(float, float) = multiply;
	std::cout <<"Calling function pointer to multiply: " << functionPointerToMutliply(70,80) << std::endl;

	//Passing function pointer to a function
    testFunctionAdd(add);
    testFunctionSubstract(substract);
    testFuntionMultiply(multiply);
    testFunctionDivide(divide);

    //Using function constuct to store the function pointers
    std::function<int(int,int)> functionAdd  = add;
    std::function<int(int,int)> functionSubstract =  substract;
    std::function<double(double,double)> functionDivide  = divide;
    std::function<float(float, float)> functionMultiply = multiply;

    std::cout <<"functionAdd:  "     << functionAdd(100,200)      << std::endl;
    std::cout <<"functionSubstract: "<< functionSubstract(300,400)<< std::endl;
    std::cout <<"functionDivide: "   << functionDivide(500,600)   << std::endl;
    std::cout <<"functionMultiply:  "<< functionMultiply(700,800) << std::endl;

	return 0;
}