#include <deque>
#include "printContainerContents.hpp"
#include "../Plane.hpp"

std::ostream& operator<<(std::ostream& os, const Plane& plane)
{
    os << "{ length: " << plane.getLength() <<  " width: " << plane.getWidth() \
        << " Area: " << plane.getAreaOfPlane() << " }";

    return os;
}

int main()
{
    /* std::deque::assign --> Assigns new contents to the deque container, replacing its 
     contents, and modifying its size accordingly */

    std::deque<int> numbers;
    std::cout << "size of the numbers : " << numbers.size() << std::endl;

    int evenNumbers[] = {2, 4, 6, 8};
    //1. range
    numbers.assign(evenNumbers, (evenNumbers + sizeof(evenNumbers)/sizeof(int)));
    printContainerContents(numbers, "evenNumbers_1");
    std::cout << "size of the numbers : " << numbers.size() << std::endl;

    //2. fill  --> assign(n, value)
    numbers.assign(5, 0);
    printContainerContents(numbers, "evenNumbers_2");
    std::cout << "size of the numbers : " << numbers.size() << std::endl;

    //3. intiailizer_list
    numbers.assign({1,3,5,7});
    printContainerContents(numbers, "evenNumbers_3");
    std::cout << "size of the numbers : " << numbers.size() << std::endl;

    Plane p1{}, p2{};
    std::deque<Plane> planeList;
    planeList.assign({p1, p2});
    printContainerContents(planeList, "planeList");
    
    return 0;
}