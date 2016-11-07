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
    /* std::forward_list::emplace_front--> Return's none*/
    std::forward_list<Plane> planes;
    planes.emplace_front();
    planes.emplace_front(4);
    planes.emplace_front(7,7);
    printContainerContents(planes, "planes");

    return 0;
}