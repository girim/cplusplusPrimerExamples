#include <iostream>
#include <thread>

void logFunction(int count)
{
	for(int index = 0; index < count; index++)
	{
		std::cout << "logFunction: count = " << index << std::endl;
	}
}

class Log
{
public:
	void operator()(int count)
	{
		for(int index = 0 ; index < count; index++)
		{
			std::cout << "Log class operator(): " << index << std::endl;
		}
	}
};

auto lambdaLog = [](int count){
	for(int index = 0; index < count; index++)
	{
		std::cout << "Lambda expression: " << index << std::endl;
	}
};

int main()
{
	std::thread threadOne(logFunction, 23);
	std::thread threadTwo(Log(), 21);
	std::thread threadThree(lambdaLog, 24);

	threadOne.join();
	threadTwo.join();
	threadThree.join();

	return 0;
}