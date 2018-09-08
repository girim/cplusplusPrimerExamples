#include <list>
#include "../printContainerContents.hpp"
#include "../Cylinder.hpp"

int main()
{
    /* std::list::assign */
    std::list<int> numbers;
    std::cout << "size of numbers: " << numbers.size() << std::endl;
    printContainerContents(numbers, "numbers_0");

    /* 1.fill(n, val) */
    numbers.assign(4, 2);
    std::cout << "size of numbers: " << numbers.size() << std::endl;
    printContainerContents(numbers, "numbers_1");

    /* 2.range(begin, end) */
    int evenNumbers[] = {2,4,6};
    numbers.assign(evenNumbers, (evenNumbers+ sizeof(evenNumbers)/sizeof(int)));
    std::cout << "size of numbers: " << numbers.size() << std::endl;
    printContainerContents(numbers, "numbers_2");

    /* 3. initializer_list */
    numbers.assign({1,3,5,7,9});
    std::cout << "size of numbers: " << numbers.size() << std::endl;
    printContainerContents(numbers, "numbers_3");

    std::list<Cylinder> cylinders;
    Cylinder c1{};
    cylinders.assign(2, c1);
    printContainerContents(cylinders, "cylinders");

    return 0;
}