#include <iostream>

template <class T>
class Test
{
public:

	void increment()
	{
		variableOne++;
	} 

	static T variableOne;
};

//initializing static members
template<typename T>
T Test<T>::variableOne = 1;

int main()
{
	Test<int> testInt;
	Test<int> testInt_2;
	Test<float> testFloat;
	std::cout << "Value of variableOne<int> is : " << Test<int>::variableOne << std::endl;
	std::cout << "Value of variableOne<float> is : " << Test<float>::variableOne << std::endl;

	testInt.increment();
	std::cout << "Value of variableOne<int> is : " << Test<int>::variableOne << std::endl;
	std::cout << "Value of variableOne<float> is : " << Test<float>::variableOne << std::endl;
	
	testInt_2.increment();
	std::cout << "Value of variableOne<int> is : " << Test<int>::variableOne << std::endl;
	std::cout << "Value of variableOne<float> is : " << Test<float>::variableOne << std::endl;
	
	return 0;
}


