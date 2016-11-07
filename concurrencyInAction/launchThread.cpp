#include <iostream>
#include <thread>

void firstThreadStartFunction()
{
	for(auto index = 0; index < 5; ++index)
		std::cout <<"[firstThread]: Running...." << std::endl;
}

void secondThreadStartFunction()
{
	for(auto index = 0; index < 5; ++index)
		std::cout <<"[secondThread]: Running...." << std::endl;
}

struct ThreadObject
{
	void operator()() const
	{
		for (auto index = 0; index < 5; ++index)
			std::cout <<"[thirdThread]: Running...." << std::endl;
	}
};

int main(int argc, char const *argv[])
{
	std::cout << "[mainThread]: Running...." << std::endl;
	std::thread firstThread(firstThreadStartFunction);

	void (*fp)() = secondThreadStartFunction;
	std::thread secondThread(fp);

	/*3 ways of passing function objects to thread*/
	ThreadObject tobj;
	std::thread thirdThread(tobj);
	std::thread thirdThread_1{ThreadObject()};
	/*If we omit () around 'threadObject()' it takes it as function declaration*/
	std::thread thirdThread_2((ThreadObject()));

	std::thread fourthThread([](){
		for(auto index = 0; index < 4; index++)
			std::cout << "[fourthThread]: Running...." << std::endl;
	});

	firstThread.join();
	secondThread.join();
	thirdThread.join();
	thirdThread_1.join();
	thirdThread_2.join();
	fourthThread.join();

	return 0;
}