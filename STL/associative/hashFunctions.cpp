#include <iostream>
#include <functional>
#include <string>

int main(int argc, char const *argv[])
{
	std::hash<std::string> hashFn;

	std::string str_1 = "Hello";
	std::string str_2 = "Hello";
	std::string str_3 = "C++";

	std::cout << "Hash# value for: " << str_1 << " is " << hashFn(str_1) << std::endl;
	std::cout << "Hash# value for: " << str_2 << " is " << hashFn(str_2) << std::endl;
	std::cout << "Hash# value for: " << str_3 << " is " << hashFn(str_3) << std::endl;

	return 0;
}