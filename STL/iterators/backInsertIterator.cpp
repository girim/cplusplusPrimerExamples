#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

int main(int argc, char const *argv[])
{
	std::list<int> primes = {1, 3, 5, 7, 9};
	std::list<int> nonPrimes = {2, 4, 6, 8};

	//containers need to have push_back() member
	std::copy(nonPrimes.begin(), nonPrimes.end(), std::back_inserter(primes));

	for(auto iter = primes.begin(); iter != primes.end(); ++iter)
		std::cout <<"Elements is: " << *iter << std::endl;

	return 0;
}