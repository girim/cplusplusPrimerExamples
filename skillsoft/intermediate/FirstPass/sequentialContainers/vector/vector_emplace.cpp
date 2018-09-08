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
    //std::vector::emplace,  Construct and insert element
    /* template <class... Args>
            iterator emplace (const_iterator position, Args&&... args); */
    std::vector<Plane> planeList;
    auto iter = planeList.emplace(planeList.begin(), 1, 4);
    planeList.emplace(iter, 8, 8);
    planeList.emplace(planeList.begin()+1, 3, 1);
    planeList.emplace(planeList.begin());  //Since 'Plane' object takes default arguments
    planeList.emplace(planeList.end(), 9);

    printVectorContents(planeList, "planeList_1");

    return 0;
}