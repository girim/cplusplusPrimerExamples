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
    // std::deque::emplace(position, Arguments) --> construct the element in place at any position
    // Return value is iter to the elment just emplaced
    std::deque<Plane> planeQueue;

    auto iter = planeQueue.emplace(planeQueue.begin());
    planeQueue.emplace(planeQueue.begin(), 9, 8);
    planeQueue.emplace(planeQueue.end(), 8);
    printContainerContents(planeQueue, "planeQueue");

    return 0;
}