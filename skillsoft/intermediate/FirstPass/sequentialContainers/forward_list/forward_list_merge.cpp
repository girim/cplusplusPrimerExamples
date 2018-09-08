#include <forward_list>
#include "../printContainerContents.hpp"
#include "../Plane.hpp"

int main()
{
    std::forward_list<double> first{4.2, 2.9, 3.1};
    std::forward_list<double> second{1.4, 7.7, 3.1};
    std::forward_list<double> third{6.2, 3,7, 7.1};

    first.sort();
    second.sort();

    printContainerContents(first, "first_before");
    printContainerContents(second, "second_before");

    first.merge(second);
    printContainerContents(first, "first_after");
    //second will be empty
    printContainerContents(second, "first_after");

    first.sort();
    third.sort();
    first.merge(third);
    printContainerContents(first, "first_after");
    printContainerContents(third, "third_after");

    return 0;
}