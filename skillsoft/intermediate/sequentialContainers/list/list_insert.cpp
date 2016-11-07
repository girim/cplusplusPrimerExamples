#include <list>
#include "../printContainerContents.hpp"
#include "../Cylinder.hpp"

int main()
{
    std::list<int> numbers;

    /* 1. single element */
    auto iter =  numbers.insert(numbers.begin(), 10);
    printContainerContents(numbers, "numbers_1");

    /* 2. fill (n, value) */
    iter = numbers.insert(iter, 4, 99);
    printContainerContents(numbers, "numbers_2");

    int evenNumbers[] ={2,4,6};
    /* 3. Range(begin, end) */
    iter = numbers.insert(iter, evenNumbers, (evenNumbers+(sizeof(evenNumbers)/sizeof(int))));
    printContainerContents(numbers, "numbers_3");
    std::cout <<"iter points to : " << *iter << std::endl;

    /* 4. Using initializer_list */
    iter = numbers.insert(iter, {1,3,7});
    printContainerContents(numbers, "numbers_3");

    return 0;
}