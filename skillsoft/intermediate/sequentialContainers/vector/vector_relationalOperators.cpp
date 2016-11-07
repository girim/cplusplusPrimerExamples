#include <vector>
#include <iostream>
#include "Plane.hpp"
#include "printVectorContents.hpp"

std::ostream& operator<<(std::ostream& os, const Plane& plane)
{
    os << "{ length: " << plane.getLength() <<  " width: " << plane.getWidth() \
        << " Area: " << plane.getAreaOfPlane() << " }";

    return os;
}

bool operator<(const Plane& lhs, const Plane& rhs)
{
    return (lhs.getAreaOfPlane() < rhs.getAreaOfPlane()) && (lhs.getLength() < rhs.getLength()) \
        && (lhs.getWidth() < rhs.getWidth());
}

bool operator>(const Plane& lhs, const Plane& rhs)
{
    return (lhs.getAreaOfPlane() > rhs.getAreaOfPlane()) && (lhs.getLength() > rhs.getLength()) \
        && (lhs.getWidth() > rhs.getWidth());
}

bool operator==(const Plane& lhs, const Plane& rhs)
{
    return (lhs.getAreaOfPlane() == rhs.getAreaOfPlane()) && (lhs.getLength() == rhs.getLength()) \
        && (lhs.getWidth() == rhs.getWidth());;
}

bool operator!=(const Plane& lhs, const Plane& rhs)
{
    return !(lhs == rhs);
}

bool operator<=(const Plane& lhs, const Plane& rhs)
{
    return ((lhs < rhs) || (lhs == rhs));
}

bool operator>=(const Plane& lhs, const Plane& rhs)
{
    return ((lhs > rhs) || (lhs == rhs));
}

int main()
{
    std::vector<int> first{1, 2, 4};
    std::vector<int> second{1, 2, 3, 4};

    if(first < second)
        std::cout << "first is less than second " << std::endl;
    
    if(second < first)
        std::cout << "second is less than first " << std::endl;

    if(first == second)
        std::cout << "first is equal to second " << std::endl;
    
    if (first != second)
        std::cout << "first is not equal to second " << std::endl;

    if (first <= second)
        std::cout << "first is less than or equal to second " << std::endl;
    
    if (first >= second)
        std::cout << "first is less greater than or equal to second " << std::endl;


    Plane p1{}, p2{}, p3{1,2}, p4{1,2};
    std::vector<Plane> planeList_1{p1, p3};
    std::vector<Plane> planeList_2{p2, p4};
    std::vector<Plane> planeList_3{p3, p4};

    printVectorContents(planeList_1, "PlaneList_1");
    printVectorContents(planeList_2, "PlaneList_2");
    printVectorContents(planeList_3, "PlaneList_3");

    if( planeList_1 == planeList_2)
        std::cout << "PlaneList_1 Equal to PlaneList_2 " << std::endl;
    
    if( planeList_1 != planeList_3)
        std::cout << "PlaneList_1 Not Equal to PlaneList_3 " << std::endl;

    if (planeList_1 < planeList_3)
        std::cout << "PlaneList_1 is Less than PlaneList_3 " << std::endl;

    if (planeList_3 > planeList_2)
        std::cout << "PlaneList_3 is Greater than PlaneList_2 " << std::endl;

    if (planeList_1 <= planeList_3)
        std::cout << "PlaneList_1 is Less than or Equal to PlaneList_3 " << std::endl;

    if (planeList_3 >= planeList_2)
        std::cout << "PlaneList_3 is Greater than or Equal to PlaneList_2 " << std::endl;

    return 0;
}