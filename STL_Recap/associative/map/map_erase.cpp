#include <iostream>
#include <map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt{}, pt1{2, 3}, pt2{5, 6}, pt3{3, 4};
    std::map<Point, unsigned> points = {{pt, 1}, {pt2, 2}, {pt3, 3}, {pt1, 4}};
    printAssocContainer(points);

    /* erase using key -- returns number of elements erased */
    auto noOfElementsErased = points.erase(pt);
    std::cout <<"Number of elements erased: " << noOfElementsErased << "\n";
    printAssocContainer(points);

    /* erase using position */
    auto iter =  points.erase(std::prev(points.end(), 3));
    std::cout << "element erased key : " << iter->first << "\n";
    std::cout << "element erased value : " << iter->second << "\n";
    printAssocContainer(points);

    /* erase range of elements */
    iter =  points.erase(points.begin(), points.end());
    printAssocContainer(points);

    return 0;
}
