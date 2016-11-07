#include <iostream>
#include <exception>

int main()
{
	try
	{
		//throw static_cast<double>(40.1);
		throw "Iron Man";
	}
	catch(int error)
	{
		std::cout << "Exception caught: " << error << std::endl;
	}
	catch(double error)
	{
		std::cout << "Exception caught: " << error << std::endl;
	}
	catch(...) //Default exception handler
	{
		std::cout << "Default exception: " << std::endl;
	}
	return 0;
}