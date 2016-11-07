#include <iostream>
#include "Matrix.hpp"

int main()
{
	Matrix<int> X(1, 2, 3, 4);
	std::cout << "Matrix X is : " << std::endl;
	X.print();

	Matrix<int> Y(3, 4, 5, 6);
	std::cout << "Matrix Y is : " << std::endl;
	Y.print(); 

	std::cout << "Matrix X + Y is:  " << std::endl;
	X.add(Y).print();

	std::cout << "Matrix X * Y is:  " << std::endl;
	X.multiply(Y).print();


	Matrix<float> U(1.1, 2.1, 3.1, 4.1);
	std::cout << "Matrix U is : " << std::endl;
	U.print();

	Matrix<float> V(3.1, 4.1, 5.1, 6.1);
	std::cout << "Matrix V is : " << std::endl;
	V.print();

	std::cout << "U + V is: " << std::endl;
	U.add(V).print();

	std::cout << "U * V is: " << std::endl;
	U.multiply(V).print();

}