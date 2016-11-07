#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
	std::vector<int> foo = {1, 2, 3, 4, 5};
	std::vector<int> bar = {10, 20, 30, 40, 50};

	std::vector<int>::iterator  iter = foo.begin();
	std::advance(iter, 4);
    
    //(sourceIterators, destinationIterators)
    std::copy(bar.begin(), bar.end(), std::inserter(foo, iter));

    for(auto element: foo)
    	std::cout <<"element is : " << element << std::endl;

    std::vector<int>::iterator it = bar.begin();
    std::advance(it, 3);

    std::insert_iterator<std::vector<int>> insertIt(bar, it);
    std::copy(foo.begin(), foo.end(), insertIt);

    for(auto element: bar)
    	std::cout << "element of bar is: " << element << std::endl;

	return 0;
}