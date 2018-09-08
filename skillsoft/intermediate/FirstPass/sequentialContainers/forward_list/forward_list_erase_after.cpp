#include <forward_list>
#include "../printContainerContents.hpp"
#include "../Plane.hpp"

int main()
{
    std::forward_list<int> numbers{10,20,30,40};
    printContainerContents(numbers, "numbers");

    auto iter =  numbers.erase_after(numbers.before_begin());
    printContainerContents(numbers, "numbers");
    std::cout << "iter points to: " << *iter << std::endl;

    iter = numbers.erase_after(iter);
    printContainerContents(numbers, "numbers");
    std::cout << "iter points to: " << *iter << std::endl;

    iter = numbers.insert_after(iter, {80, 70, 90, 50});
    printContainerContents(numbers, "numbers");
    std::cout << "iter points to: " << *iter << std::endl;

    iter = numbers.erase_after(numbers.before_begin(), numbers.end());
    printContainerContents(numbers, "numbers");

    return 0;
}