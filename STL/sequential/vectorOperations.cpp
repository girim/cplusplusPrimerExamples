#include <iostream>
#include <vector>

void drawADottedLine()
{
	std::cout << "------------------------" << std::endl;  
}

template<typename T>
void print(const T& vec)
{
	for(typename T::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
		std::cout << "Element is : " << *iter << std::endl;	
	drawADottedLine();
}

int main()
{
	/*vector::assign*/
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;
	std::vector<double> fourth;
	std::vector<int> fifth(10);
	int numbers[] = {1,2,3,4,5,6,7,8};

	//3 ways
	first.assign(7, 4);        //size and value
	second.assign(first.begin()+1, first.end()-2); //Using iterator Range
	third.assign(numbers, (numbers + sizeof(numbers) / sizeof(int))); //Iterator Range
	fourth.assign({2.2, 1.1, 4.4, 8.8});   //Using initializer list

	print(first);
	print(second);
	print(third);
	print(fourth);

	drawADottedLine();
	/*vector::at(n) --> returns reference to the element at position 'n'*/
	std::cout << "element at position 1 is :first.at(1) " << first.at(1) << std::endl;
	first.at(1) = 8;
	print(first);

	/*vector::back & vector::front*/
	print(fourth);
	std::cout << "element at the back is fourth.back() : " << fourth.back() << std::endl;
	std::cout << "element at the front is fourth.front(): " << fourth.front() << std::endl;

	/*vector::capacity, vector::max_size*/
	std::cout << "capacity of the vector is (second.capacity) " << (int)second.capacity() << std::endl;
	std::cout << "size of the vector is (second.size()): " << (int)second.size() << std::endl;
	second.push_back(20);
	second.push_back(21);
	std::cout << "capacity of the vector is (second.capacity) " << (int)second.capacity() << std::endl;
	std::cout << "size of the vector is (second.size()): " << (int)second.size() << std::endl;
	std::cout << "max_size is : " << second.max_size()  << std::endl;

	/*vector::clear*/
	fifth.clear();
	print(fifth);

	first.assign({1,2,3,4,5,6,7,8});
	/*vector::rbegin, vector::rend*/
	for(std::vector<int>::reverse_iterator iter = first.rbegin(); iter != first.rend(); ++iter)
		std::cout << "Elements are first.rbegin, first.rend " << *iter << std::endl;

	/*vector::data*/
	int *ptrToElement = first.data();
	std::cout << "ptrToElement is: " << *ptrToElement << std::endl;
	ptrToElement++;
	std::cout << "ptrToElement is: " << *ptrToElement << std::endl;

	ptrToElement[3] = 100;
	print(first);

	/*vector::emplace*/
	auto iter = first.emplace(first.begin()+2, 44);
	first.emplace(iter, 88);
	print(first);

	/*vector::emplace_back*/
	first.emplace_back(2);
	first.emplace_back(7);
	print(first);

	/*vector::erase*/
	first.erase(first.begin()+2);
	print(first);

	first.erase(first.begin()+2, first.end()-2);
	print(first);

	return 0;
}