#include <vector>
#include "printVectorContents.hpp"
#include "Plane.hpp"

std::ostream& operator<<(std::ostream& os, const Plane& plane)
{
    os << "{ length: " << plane.getLength() <<  " width: " << plane.getWidth() \
        << " Area: " << plane.getAreaOfPlane() << " }";

    return os;
}

int main()
{
    Plane p1{}, p2{};
    Plane p3{2,2}, p4{4,4};

    std::vector<Plane> defaultPlanes{p1, p2};
    std::vector<Plane> planes{p3, p4};

    printVectorContents(defaultPlanes, "defaultPlanes[Before]");
    printVectorContents(planes, "defaultPlanes[Before]");

    //Swap the contents of the vectors and resize accordingly
    defaultPlanes.swap(planes);

    printVectorContents(defaultPlanes, "defaultPlanes[After]");
    printVectorContents(planes, "defaultPlanes[After]");

    std::vector<int> evenNumbers{2, 4, 6};
    std::vector<int> oddNumbers{1, 3};

    evenNumbers.swap(oddNumbers);
    
    printVectorContents(evenNumbers, "evenNumbers");
    printVectorContents(oddNumbers, "oddNumbers");

    return 0;
}