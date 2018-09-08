#include <forward_list>
#include "../printContainerContents.hpp"
#include "../Plane.hpp"

int main()
{
    std::forward_list<int> numbers{10, 20, 30, 40};
    printContainerContents(numbers, "numbers_0");

    numbers.reverse();
    printContainerContents(numbers, "numbers_1");

    Plane p1{0,0}, p2{3,2}, p3{8,9};
    std::forward_list<Plane> planes{p3, p2, p1};
    printContainerContents(planes, "planes");

    planes.reverse();
    printContainerContents(planes, "planes");

    return 0;
}