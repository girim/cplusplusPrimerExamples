#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

#define EOL "\n"

template<typename T>
void printContainer(const T& container)
{
    for(auto iter = container.cbegin(); iter != container.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << EOL;
}

int main(int argc, char const *argv[])
{
    std::vector<int> numbers = {1, 3, 5, 7, 9};
    std::vector<int>::iterator start = numbers.begin();

    std::advance(start, 3);
    std::cout << "Fourth prime number is : " << *start << EOL;
    std::cout <<"Distance between begin and end: " << std::distance(numbers.begin(), numbers.end()-1) << EOL;

    std::for_each(numbers.begin(), std::next(numbers.begin(), 3), [](int x){
        std::cout << "element is : " <<  x << EOL;
    });

    std::for_each(numbers.begin(), std::prev(numbers.end(), 2), [](int x){
        std::cout << "element is: " << x << EOL;
    });

    return 0;
}

