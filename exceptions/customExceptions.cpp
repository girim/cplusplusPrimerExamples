#include <iostream>
#include <exception>

class CustomException : public std::exception
{
	public:
		//dynamic exception specification so using 'throw()'
		virtual const char* what() const throw()
		{
			return "CustomException: "; //std::unexpected is called
		}	 
}customExceptionType;

int main()
{
	//throw CustomExceptionType;
	try
	{
		throw customExceptionType;
		std::cout << "Just after throwing the exception...." << std::endl;
	}
	catch(std::exception &error) //customException will be caught here 
	{
		std::cout << "Exception caught: std::exception handler ...." << std::endl;
	}
	catch(CustomException &error)
	{
		std::cout << "Exception caught: " << error.what() << std::endl;
	}

	std::cout << "End of the program reached ...." << std::endl;

	return 0;
}