#include <iostream>
#include <thread>
#include <functional>
#include <mutex>

struct threadHost
{
	int &count_;

	threadHost(int &count): count_(count)
	{

	}

	~threadHost() = default;

	void operator()()
	{	
		++count_;
		for(int index = 0; index < count_; ++index)
			std::cout << "Running loop : " << index << std::endl; 
	}
};

//RAII implementation
class threadGuard
{
public:
	explicit threadGuard(std::thread &t) : thread_(t)
	{

	}

	~threadGuard()
	{
		if(thread_.joinable())
		{
		    std::cout << "Thread destuctor called ...." << std::endl;
			thread_.join();
		}
	}

	threadGuard(const threadGuard& tg)=delete; //copy constuctor
	threadGuard& operator=(const threadGuard& tg)=delete;

private:
	std::thread& thread_;
};

int main(int argc, char const *argv[])
{
	int loopCount = 4;
	threadHost threadhost(loopCount);
	std::thread th(std::ref(threadhost));
	//std::thread th(std::ref(threadhost));

	threadGuard tg(th);
	std::cout <<"Count value is: " << ++threadhost.count_ << std::endl;
	//threadHost ths(loopCount);
	//std::cout << "Count value : " << ++ths.count_ << std::endl;
	std::cout << "Count value : " << loopCount<< std::endl;

	return 0;
}