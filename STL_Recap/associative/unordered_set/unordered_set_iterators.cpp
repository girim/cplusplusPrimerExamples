#include <iostream>
#include <unordered_set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2};
    std::unordered_set<Point, Point> points = {pt0, pt1, pt2};
    printAssocContainer(points);

    /* unordered_set uses "Forward Iterators" */
    /* [begin, end) */
    for(std::unordered_set<Point, Point>::iterator iter =  points.begin(); iter != points.end(); ++iter)
    {
        std::cout << "key/value: " << *iter << "\n";
    }
    std::cout << "\n";

    /* [cbegin, cend) */
    for(std::unordered_set<Point, Point>::const_iterator iter = points.cbegin(); iter != points.cend(); ++iter)
    {
        std::cout << "key/value: " << *iter << "\n";
    }
    std::cout << "\n";
    
    return 0;
}
