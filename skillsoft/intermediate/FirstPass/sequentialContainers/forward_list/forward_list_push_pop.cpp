#include <forward_list>
#include "../printContainerContents.hpp"
#include "../Plane.hpp"

std::ostream& operator<<(std::ostream& os, const Plane& plane)
{
    os << "{ length: " << plane.getLength() <<  " width: " << plane.getWidth() \
        << " Area: " << plane.getAreaOfPlane() << " }";

    return os;
}

int main()
{
    std::forward_list<int> numbers{0, 1, 2};
    printContainerContents(numbers, "numbers");

    numbers.push_front(10);
    numbers.push_front(20);
    printContainerContents(numbers, "numbers");

    numbers.push_front(40);
    numbers.push_front(30);
    printContainerContents(numbers, "numbers");

    numbers.pop_front();
    printContainerContents(numbers, "numbers");

    numbers.pop_front();
    numbers.pop_front();
    printContainerContents(numbers, "numbers");

    Plane p1{}, p2{1,1};
    std::forward_list<Plane> planeList;
    planeList.push_front(p1);
    planeList.push_front(p2);
    printContainerContents(planeList, "planeList");

    planeList.pop_front();
    printContainerContents(planeList, "planeList");
    
    return 0;
}