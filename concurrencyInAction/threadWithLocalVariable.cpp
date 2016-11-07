#include <iostream>
#include <thread>

class functor
{
	public:
		functor(int& count): count_(count){ };
		~functor() = default;

		void operator()()
		{
			for(int index = 0; index < 1000; ++index)
				std::cout << "count is: " << count_ << std::endl;
		}

	private:
		int &count_;
};

int main(int argc, char const *argv[])
{
	int counter = 4;
	functor func(counter);

	std::thread firstThread(func);
	//firstThread.detach();
	firstThread.join();

	return 0;
}