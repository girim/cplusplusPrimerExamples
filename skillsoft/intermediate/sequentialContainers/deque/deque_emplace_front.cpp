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

    planes.emplace_front();
    printContainerContents(planes, "planes");

    planes.emplace_front(4);
    printContainerContents(planes, "planes");

    planes.emplace_front(9,9);
    printContainerContents(planes, "planes");
    
    return 0;
}