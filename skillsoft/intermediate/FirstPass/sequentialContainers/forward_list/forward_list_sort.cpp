#include <forward_list>
#include <functional>
#include "../printContainerContents.hpp"
#include "../Plane.hpp"

int main()
{
    std::forward_list<int> numbers{10, 9, 20, 4, 1, 13};
    printContainerContents(numbers, "numbers_1");

    numbers.sort();
    printContainerContents(numbers, "numbers_2");
    
    numbers.sort(std::greater<int>());
    printContainerContents(numbers, "numbers_3");

    Plane p1{2,4}, p2{2,1}, p3{0,0}, p4{4,5};
    std::forward_list<Plane> planeList{p1, p2, p3, p4};
    printContainerContents(planeList, "planeList");

    planeList.sort([](const Plane& lhs, const Plane& rhs){
        return (lhs.getAreaOfPlane() < rhs.getAreaOfPlane());
    });
    printContainerContents(planeList, "planeList");

    planeList.sort([](const Plane& lhs, const Plane& rhs){
        return (lhs.getWidth() < rhs.getWidth());
    });
    printContainerContents(planeList, "planeList");

    planeList.sort([](const Plane& lhs, const Plane& rhs){
        return (lhs.getLength() > rhs.getLength());
    });
    printContainerContents(planeList, "planeList");

    return 0;
}