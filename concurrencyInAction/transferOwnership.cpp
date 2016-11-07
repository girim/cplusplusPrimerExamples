#include <iostream>
#include <thread>

void callbackFunction_1()
{
	std::cout << "Callback_function_1 called ...." << std::endl;
}

void callbackFunction_2()
{
	std::cout << "Callback_function_2 called ...." << std::endl;
}

/*Returning a thread from function*/
std::thread getThread_1(std::function<void()> callback)
{
	std::cout << "Thread creator 1 ...." << std::endl;
	return std::thread(callback); //un-named thread obj
} 

std::thread getThread_2(std::function<void()> callback)
{
	std::cout << "Thread creator 2 ...." << std::endl;
	std::thread tmp(callbackFunction_2); //named thread obj
	return tmp;
}

void someFunction(std::thread t)
{
	std::cout << "Some function ...." << std::endl;
	t.join();
}

int main(int argc, char const *argv[])
{
	std::thread t1 = getThread_1(callbackFunction_1);
	t1.join();
	getThread_2(callbackFunction_2).join();

	someFunction(std::thread(callbackFunction_1));
	std::thread temp(callbackFunction_2);
	someFunction(std::move(temp));

	return 0;
}