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
    std::deque<Plane> planes;

    planes.emplace_back();
    printContainerContents(planes, "planes");

    planes.emplace_back(2);
    printContainerContents(planes, "planes");
    
    planes.emplace_back(7,8);
    printContainerContents(planes, "planes");

    return 0;
}