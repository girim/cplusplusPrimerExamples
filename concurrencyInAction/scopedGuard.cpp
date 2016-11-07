#include <iostream>
#include <thread>
#include <exception>

struct callback
{
	int count_;
	callback(int count = 1) : count_(count) {};
	~callback(){};

	void operator()()
	{
		for(auto index = 0; index < count_; ++index)
			std::cout <<"Running loop with itration : " << index << std::endl;
	} 
};

class ScopedThread
{
public:
	explicit ScopedThread(std::thread t) : thread_(std::move(t))
	{
		if (!thread_.joinable())
			throw std::logic_error("No thread");
	}

	~ScopedThread()
	{
		std::cout << "ScopedThread destructor called ...." << std::endl;
		thread_.join();
	}

	ScopedThread(ScopedThread &st)=delete;
	ScopedThread& operator=(ScopedThread &st)=delete;

private:
	std::thread thread_;
};

int main(int argc, char const *argv[])
{
	callback cb;
	std::thread t(cb);
	ScopedThread scopedThread(std::move(t));

	//t.join();
	callback cb_1(4);
	ScopedThread scopedThread_1(std::thread{cb_1});
	return 0;
}