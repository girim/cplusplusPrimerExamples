#include <iostream>

int main(int argc, char const *argv[])
{
	std::cout << "Function name: " << __func__ << std::endl;
	std::cout << "File name: " << __FILE__ << std::endl;
	std::cout << "Line no: " << __LINE__ << std::endl;
	std::cout << "Date: " << __DATE__ << std::endl;

	return 0;
}