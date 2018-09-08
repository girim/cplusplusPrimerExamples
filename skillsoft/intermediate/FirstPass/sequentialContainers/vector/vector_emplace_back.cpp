#include <vector>
#include "Plane.hpp"
#include "printVectorContents.hpp"

std::ostream& operator<<(std::ostream& os, const Plane& plane)
{
    os << "{ length: " << plane.getLength() <<  " width: " << plane.getWidth() \
        << " Area: " << plane.getAreaOfPlane() << " }";

    return os;
}

int main()
{
    std::vector<Plane> planeList;
    planeList.emplace_back();

    printVectorContents(planeList, "planeList_1");

    return 0;
}