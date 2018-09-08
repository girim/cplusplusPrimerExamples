#include <deque>
#include <iostream>
#include "printContainerContents.hpp"

int main()
{
    //1. empty constructor
    std::deque<int> emptyQueue;

    //2. fill constructor std::deque(n)
    std::deque<float> fractions(4);
    printContainerContents(fractions, "fractions");

    //2. fill constructor std::deque(n, val)
    std::deque<double> prices(5, 8.8);
    printContainerContents(prices, "prices");

    //3. Using Range constructor
    std::deque<double> numbers(prices.begin(), prices.end());
    printContainerContents(numbers, "numbers");

    int oddNumbers[] = {1, 3, 5, 7};
    std::deque<int> odds(oddNumbers, (oddNumbers + sizeof(oddNumbers)/sizeof(int))) ;
    printContainerContents(odds, "odds");

    //4. Using copy constructor
    std::deque<float> copyOfFractions(fractions);
    printContainerContents(copyOfFractions, "copyOfFractions");

    //5. Using intializer_list
    std::deque<int> evenNumbers({2,4,6,8});
    printContainerContents(evenNumbers, "evenNumbers");

    //6. Using move constructor
    std::deque<int> integers(std::move(evenNumbers));
    printContainerContents(integers, "intergers");
    printContainerContents(evenNumbers, "evenNumbers");

    return 0;
}