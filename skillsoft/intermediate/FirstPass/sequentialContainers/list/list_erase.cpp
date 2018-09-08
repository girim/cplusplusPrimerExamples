#include <list>
#include "../printContainerContents.hpp"

int main()
{
    std::list<int> numbers{10,30,40,50};
    printContainerContents(numbers, "numbers");

    auto iter  = numbers.begin();
    ++iter;
    auto it = numbers.erase(iter);
    printContainerContents(numbers, "numbers");

    it = numbers.erase(it);
    printContainerContents(numbers, "numbers");

    it = numbers.erase(it);
    printContainerContents(numbers, "numbers");

    /* Using range to erase(begin, end) */
    numbers.erase(numbers.begin(), numbers.end());
    printContainerContents(numbers, "numbers");

    return 0;
}