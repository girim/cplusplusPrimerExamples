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
    /* 1. empty constructor */
    std::forward_list<int> firstList;

    /* 2. fill constructor (n, value) */
    std::forward_list<double> secondList(4, 3.1412);
    printContainerContents(secondList, "secondList");

    /* std::forward_list(n) */
    std::forward_list<int> thirdList(3);
    printContainerContents(thirdList, "thirdList");

    /* 3. Range constructor (begin, end)*/
    std::forward_list<double> fourthList(secondList.begin(), secondList.end());
    printContainerContents(fourthList, "fourthList");

    /* 4. copy constructor */
    std::forward_list<double> fifthList(secondList);
    printContainerContents(fifthList, "fifthList");

    /* 5. initializer_list */
    Plane p1{}, p2{1,1}, p3{2,2};
    std::forward_list<Plane> planeList({p1, p2});
    printContainerContents(planeList, "planeList");
    
    planeList.push_front(p3);
    printContainerContents(planeList, "planeList");
    
    /* 6. move constructor */
    std::forward_list<Plane> planeList_1(std::move(planeList));
    printContainerContents(planeList_1, "planeList_1");

    return 0;
}