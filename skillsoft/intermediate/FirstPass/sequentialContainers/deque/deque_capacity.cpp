#include <deque>
#include "printContainerContents.hpp"

int main()
{
    std::deque<int> numbers{1,2,3,4};

    //1. std::deque::size() --> returns the no of elements currently stored in the deque
    std::cout << "size of numbers is: " << numbers.size() << std::endl;

    //2. std::deque::max_size() --> returns the max number elements that can be stored in deque.
    std::cout << "max_size of numbers is: " << numbers.max_size() << std::endl;

    //3. std::deque::resize() --> changes the size of the deque
    numbers.resize(6);
    printContainerContents(numbers, "numbers");

    numbers.resize(9, 22);
    printContainerContents(numbers, "numbers");

    numbers.resize(3);
    printContainerContents(numbers, "numbers");

    //4. shrink_to_fit
    numbers.shrink_to_fit();
    std::cout << "size of numbers is: " << numbers.size() << std::endl;

    //5. empty
    std::cout << "is empty: " << std::boolalpha << numbers.empty() << std::endl;
    numbers.clear();
    std::cout << "is empty: " << std::boolalpha << numbers.empty() << std::endl;



    return 0;
}