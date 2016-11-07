#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
	std::vector<int> inputPassed(4);

	std::cout << "Enter the characaters (hit any number to stop) ";
	std::istream_iterator<int> iter(std::cin);

	std::copy(iter, std::istream_iterator<int>(), inputPassed.begin());
	std::cin.clear();

	for(auto ch : inputPassed)
		std::cout << "character entered is : " << ch << std::endl;

	return 0;
}