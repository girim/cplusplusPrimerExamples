#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main(int argc, char const *argv[])
{
	std::vector<int> numbers{1,2,3,4,5,6,7,8,9};

	const char* delimiter = ": ";
	std::ostream_iterator<int> printout(std::cout, delimiter);

	std::copy(numbers.begin(), numbers.end(),printout);
	std::cout << std::endl;

	return 0;
}