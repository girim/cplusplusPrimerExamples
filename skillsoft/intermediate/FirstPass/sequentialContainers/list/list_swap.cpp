#include <list>
#include "../printContainerContents.hpp"

int main()
{
    std::list<int> first{1, 3, 7, 5};
    std::list<int> second{2, 4, 6, 8};

    printContainerContents(first, "firstBeforeSwap");
    printContainerContents(second, "secondBeforeSwap");

    first.swap(second);

    printContainerContents(first, "firstAfterSwap");
    printContainerContents(second, "secondAfterSwap");
    
    return 0;
}