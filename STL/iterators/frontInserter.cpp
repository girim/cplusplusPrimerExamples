#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>

int main(int argc, char const *argv[])
{
	std::deque<char> firstQue = {'o', 'u', 's'};
	std::deque<char> secondQue = {'a', 'e', 'i'};

	std::copy(secondQue.begin(), secondQue.end(), std::front_inserter(firstQue));

	for(auto iter = firstQue.begin(); iter != firstQue.end(); ++iter)
		std::cout << "Element is : " << *iter << std::endl; 

	return 0;
}