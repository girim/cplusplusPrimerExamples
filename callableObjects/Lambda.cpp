	#include <iostream>

	int main()
	{
		auto lambda_1 =  [](const int &number)-> bool {
			return (((number % 2) == 0) ? true : false);
		};

		auto lambda_2 =  []{
			return 400;
		};

		auto lambda_3 =  []()-> int {
			return true;
		};

	    std::cout << "lambda_1: " << lambda_1(20) << std::endl;
	    std::cout << "lambda_2: " << lambda_2() << std::endl;
	    std::cout << "lambda_3: " << lambda_3() << std::endl;

		return 0;
	}