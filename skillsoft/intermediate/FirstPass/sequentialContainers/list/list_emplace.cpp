#include <list>
#include "../printContainerContents.hpp"
#include "../Cylinder.hpp"

int main()
{
    /* std::list::emplace(position, Args) --> returns iter to the emplaced element */
    std::list<int> numbers;
    auto iter  = numbers.emplace(numbers.begin(), 10);
    iter = numbers.emplace(iter, 30);
    iter = numbers.emplace(iter, 20);
    iter = numbers.emplace(iter, 80);
    iter = numbers.emplace(numbers.begin(), 70);

    printContainerContents(numbers, "numbers");

    std::list<Cylinder> cylinders;
    auto it = cylinders.emplace(cylinders.begin());
    it = cylinders.emplace(it, 5);
    it = cylinders.emplace(it, 2, 3);

    printContainerContents(cylinders, "cylinders");


    return 0;
}