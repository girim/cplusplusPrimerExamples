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
    /* 1. push_front --> enqueues elements at the begining of deque
       2. pop_ front --> dequeues elements at the begining of deque
       3. push_back  --> enqueues elements at the end of the deque
       4. pop_back   --> dequeues elements at the end of the deque

        Return type is 'void' for all of the above API's   
    */
    std::deque<int> numbers;

    numbers.push_front(10);
    numbers.push_front(20);
    numbers.push_back(5);
    numbers.push_back(4);
    printContainerContents(numbers, "numbers");
    
    numbers.push_back(0);
    numbers.push_front(0);
    printContainerContents(numbers, "numbers");

    numbers.pop_front();
    printContainerContents(numbers, "numbers");

    numbers.pop_back();    
    printContainerContents(numbers, "numbers");

    Plane p1{}, p2{1,4};
    std::deque<Plane> planeList;
    planeList.push_front(p1);
    printContainerContents(planeList, "planeList_1");
    planeList.push_front(p2);
    printContainerContents(planeList, "planeList_2");

    planeList.pop_back();
    printContainerContents(planeList, "planeList_3");
    planeList.pop_front();
    
    return 0;
}