#include <list>
#include "../printContainerContents.hpp"

int main()
{
    std::list<int> numbers{1,2,3,4};
    printContainerContents(numbers, "numbers");
    std::cout << "size of the numbers: " << numbers.size() << std::endl;

    numbers.resize(2);
    printContainerContents(numbers, "numbers");
    std::cout << "size of the numbers: " << numbers.size() << std::endl;

    numbers.resize(6, 99);
    printContainerContents(numbers, "numbers");
    std::cout << "size of the numbers: " << numbers.size() << std::endl;

    return 0;
}