#include <iostream>
#include <deque>

class dummyClass
{
public:
	explicit dummyClass(std::string name = "undefined", int count = 0) : \
		name_(name), count_(count){};
	~dummyClass() = default;
	
	std::string getName()
	{
		return name_;
	}

	int getCount()
	{
		return count_;
	}

private:
	std::string name_;
	int count_;
};

void drawDottedLine()
{
	std::cout << "-----------------------------" << std::endl;
}

template<typename T>
void printContainer(const T& container)
{
	drawDottedLine();
	for(typename  T::const_iterator iter = container.begin(); 
			iter != container.end(); ++iter)
	{
		std::cout << "element is : " << *iter << std::endl;
	}
	drawDottedLine();
}

template<typename T>
void printContainerInReverse(const T& container)
{
	drawDottedLine();
	for(typename  T::const_reverse_iterator iter = container.crbegin(); 
			iter != container.crend(); ++iter)
	{
		std::cout << "element is : " << *iter << std::endl;
	}
	drawDottedLine();
}

int main(int argc, char const *argv[])
{
	std::deque<int> dq_1;
	dq_1.push_back(10);
	dq_1.push_back(20);

	printContainer(dq_1);
	printContainerInReverse(dq_1);

	dq_1.push_front(30);
	dq_1.push_front(40);
	printContainer(dq_1);

	dq_1.pop_front();
	printContainer(dq_1);

	dq_1.pop_back();
	printContainer(dq_1);

	dq_1.insert(dq_1.begin(), {80,90,70});
	printContainer(dq_1);

	dummyClass dummy;
	std::cout << "Name is : " << dummy.getName() << std::endl;

	std::deque<dummyClass> dummyQ;
	dummyQ.emplace(dummyQ.begin(), "girim", 123);

	std::cout << "Name is : " << dummyQ.at(0).getName() << std::endl; 
	std::cout << "Count is : " << dummyQ.at(0).getCount() << std::endl; 


	/*std::deque.swap*/
	std::deque<int> foo(3, 9);
	std::deque<int> bar(4, 8);

	std::cout <<"Before swap: " << std::endl;
	printContainer(foo);
	printContainer(bar);

	foo.swap(bar);
	std::cout <<"After swap: " << std::endl;
	printContainer(foo);
	printContainer(bar);

	return 0;
}