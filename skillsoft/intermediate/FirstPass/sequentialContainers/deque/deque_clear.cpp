#include <deque>
#include "printContainerContents.hpp"

int main()
{
    std::deque<int> numbers(4, 9);
    printContainerContents(numbers, "numbers_1");
    std::cout << "size of the numbers: " << numbers.size() << std::endl;

    numbers.clear();

    printContainerContents(numbers, "numbers_2");
    std::cout << "size of the numbers: " << numbers.size() << std::endl;

    return 0;
}