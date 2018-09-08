#include <iostream>
#include <unordered_map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4};
    std::unordered_map<Point, unsigned, Point> points;
    
    /* pair<Iter to emplaced element, result of insertion> */
    std::pair<std::unordered_map<Point, unsigned, Point>::iterator, bool> iter = points.emplace(pt0, 1);
    printAssocContainer(points);

    std::cout << "Element emplace: Key: " << iter.first->first << " Value: " << iter.first->second << " result: " << iter.second << "\n";

    iter = points.emplace(pt1, 2);
    iter = points.emplace(pt2, 3);
    iter = points.emplace(pt3, 4);
    printAssocContainer(points);

    iter = points.emplace(pt1, 5);
    std::cout << "Element emplace: Key: " << iter.first->first << " Value: " << iter.first->second << " result: " << iter.second << "\n";

    /* emplace_hint */
    auto itr = points.emplace_hint(points.end(), pt4, 6);
    printAssocContainer(points);

    return 0;
}
