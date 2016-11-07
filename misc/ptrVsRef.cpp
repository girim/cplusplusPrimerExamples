#include <iostream>

int main(int argc, char const *argv[])
{
	int var = 10;
	const int &ref = var;
	int *ptr = &var;
	int *ptrCpy = ptr;

	ref = 30;
	std::cout << "Address of var: " << &var << std::endl;
	std::cout << "Address of ref: " << &ref << std::endl;
	std::cout << "Address of ptr: " << &ptr << std::endl;
	std::cout << "Address of ptrCpy: " << &ptrCpy << std::endl;
	std::cout << "size of ref: " << sizeof(ref) << std::endl;

	return 0;
}