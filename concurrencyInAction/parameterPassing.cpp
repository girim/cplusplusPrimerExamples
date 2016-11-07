#include <iostream>
#include <thread>
#include <functional>
#include <string>

/*Function that does not take any arguments*/
void callbackFunction_0()
{
	//std::cout << "callbackFunction with 0 argument called ...." << std::endl;
}

void callbackFunction_1(int count)
{
	//std::cout << "callbackFunction with 1 argument called ...." << std::endl;
	for(int index = 0; index < count; ++index)
		std::cout << "counter value : " << index << std::endl;
}

void callbackFunction_2(int count, std::string name)
{
	//std::cout << "callbackFunction with 2 arguments called ...." << std::endl;
	//for(int index = 0; index < count; ++index)
		//std::cout << "Running " << name << std::endl;
}

/*Using function object*/
struct FuncObject
{
	//const int &count_;
	int count_;
	FuncObject(int count = 1) : count_(count) {};

	void operator()()
	{
		for(int index = 0; index < count_; ++index)
			std::cout <<"FunctionObject loop index: " << index << std::endl;
	}

	void operator()(const std::string& name)
	{
		for(int index =0; index < count_; ++index)
			std::cout <<"FunctionObject loop for : "  << index  << " " << name<< std::endl;
	}
};

class WorkerThread
{
	public:
		explicit WorkerThread(const unsigned count = 1): count_(count) {};
		~WorkerThread(){};

		void workerThreadInit()
		{
			for(auto index = 0; index < count_; index++)
				std::cout << "Running WorkerThread loop  iteration: " << index << std::endl;
		}

	private:
		const unsigned count_;
};


int main(int argc, char const *argv[])
{
	std::thread firstThread(callbackFunction_0);
	std::thread secondThread(callbackFunction_1, 4);
	std::string str = "thirdThread";
	std::thread thirdThread(callbackFunction_2, 7, str);

	char letters[4] = {'a', 'b', 'c', 'd'};
	std::thread fourthThread(callbackFunction_2, 2, std::string(letters));

    FuncObject funcOne(2);
    //funcOne();
    //funcOne(std::string("Hello"));

    std::thread fifthThread(funcOne);
    std::thread sixthThread(funcOne, std::string("sixthThread"));

    WorkerThread wt(4);
    std::thread seventhThread(&WorkerThread::workerThreadInit, &wt);

    //Using pointer to member function
    void (WorkerThread::*ptrToWorkerThread)() = &WorkerThread::workerThreadInit;
    std::thread eigthThread(ptrToWorkerThread, &wt);

	thirdThread.join();
	secondThread.join();
	firstThread.join();
	//fourthThread.join();
	fourthThread.detach();
	fifthThread.join();
	sixthThread.join();
	seventhThread.join();
	eigthThread.join();

	return 0;
}
