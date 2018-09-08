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
    /* std::forward_list::assign */
    std::forward_list<int> numbers;

    /* 1. range */
    int oddNumbers[] = {1, 3, 5, 7};
    numbers.assign(oddNumbers, (oddNumbers + sizeof(oddNumbers)/sizeof(int)));
    printContainerContents(numbers, "numbers");

    /* 2. fill (n, value)*/
    numbers.assign(6, 3);    
    printContainerContents(numbers, "numbers");

    /* 3. intializer_list */
    numbers.assign({10, 20, 40});
    printContainerContents(numbers, "numbers");

    Plane p1{}, p2{2,2}, p3{3,3};
    std::forward_list<Plane> planeList{p1};
    printContainerContents(planeList, "planeList");

    planeList.assign({p2, p3});
    printContainerContents(planeList, "planeList");

    return 0;
}