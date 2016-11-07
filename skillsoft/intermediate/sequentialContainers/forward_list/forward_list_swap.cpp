#include <forward_list>
#include "../printContainerContents.hpp"

int main()
{
    std::forward_list<int> firstList{0,0,0};
    std::forward_list<int> secondList{10,20,30};

    printContainerContents(firstList, "firstList");
    printContainerContents(secondList, "secondList");

    firstList.swap(secondList);

    printContainerContents(firstList, "firstList");
    printContainerContents(secondList, "secondList");

    return 0;
}