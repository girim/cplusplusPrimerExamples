#include <iostream>
#include <thread>
#include <stdexcept>

void startNewThread()
{
	std::cout << "Started new thread ...." << std::endl;
}

int main(int argc, char const *argv[])
{
	std::thread firstThread(startNewThread);

	try
	{
		throw std::out_of_range("messagemake");
	}
	catch(...)
	{
		firstThread.join();
		throw;
	}
	firstThread.join();

	return 0;
}