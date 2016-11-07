#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

void callback(unsigned id)
{
	std::cout << "thread with id: " << id << " Running...." << std::endl; 
	std::cout << "threadId: "  << std::this_thread::get_id() << std::endl;
}

void joinThread(std::thread t)
{
	t.join();
}

struct funObj
{
	std::thread t_;
	funObj()=default;
	~funObj(){};
	funObj(funObj &&fo) noexcept : t_(std::move(fo.t_)){
		std::cout <<"moving obj: " << std::endl;
	};

	funObj(funObj& fo) = delete;
	funObj& operator=(funObj& fo) = delete;

	void operator()(std::thread &t)
	{
		t.join();
	}
};

int main(int argc, char const *argv[])
{
	std::vector<std::thread> threadList;

	for(unsigned index = 0; index < 5; index++)
		threadList.push_back(std::thread(callback, index));

	//std::for_each(threadList.begin(), threadList.end(), std::mem_fn(&std::thread::join));
	/*Better to use above function instead of writing own move-constuctible function object*/
	//std::for_each(threadList.begin(), threadList.end(), joinThread);
	//funObj fn;
	std::for_each(threadList.begin(), threadList.end(), funObj());

	std::thread tmp;
	std::cout <<"Thread id of tmp is: "<< tmp.get_id() << std::endl;

	return 0;
}