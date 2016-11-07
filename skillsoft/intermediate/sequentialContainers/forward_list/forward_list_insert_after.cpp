#include <forward_list>
#include "../printContainerContents.hpp"

int main()
{
    std::forward_list<int> numbers{0};
    auto iter = numbers.insert_after(numbers.before_begin(), 2, 99);
    printContainerContents(numbers, "numbers");

    /* single element */
    iter = numbers.insert_after(iter, 100);
    printContainerContents(numbers, "numbers");

    /* fill(n, value) */
    iter = numbers.insert_after(iter, 2, 1);
    printContainerContents(numbers, "numbers");

    /*initializer_list  */
    iter = numbers.insert_after(iter, {77,88,99});
    printContainerContents(numbers, "numbers");

    int evens[] = {222, 888};
    /* range (begin, end) */
    iter = numbers.insert_after(iter, evens, (evens + sizeof(evens)/sizeof(int)));
    printContainerContents(numbers, "numbers");
    
    return 0;
}