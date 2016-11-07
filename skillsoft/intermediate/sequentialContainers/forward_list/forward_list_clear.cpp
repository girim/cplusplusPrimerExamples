#include <forward_list>
#include "../printContainerContents.hpp"

int main()
{
    std::forward_list<int> evenNumbers{2, 4, 6, 8};
    printContainerContents(evenNumbers, "evenNumbers");

    evenNumbers.clear();
    printContainerContents(evenNumbers, "evenNumbers");

    return 0;
}