#include <iostream>
#include <map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt{}, pt1{1, 1}, pt2{2, 2}, pt3{3, 3};
    std::map<Point, unsigned> points = {{pt, 1}, {pt1, 2}, {pt2, 3}, {pt3, 4}};

    auto lowerIter = points.lower_bound(pt1);
    printAssocContainer(points);

    std::cout << "key: " << lowerIter->first << " value: " << lowerIter->second << "\n";

    auto upperIter = points.upper_bound(pt1);
    std::cout << "key: " << upperIter->first << " value: " << upperIter->second << "\n";

    auto range = points.equal_range(pt2);
    std::cout << "LowerBound: key: " << range.first->first << " val: " << range.first->second << "\n";
    std::cout << "UpperBound: key: " << range.second->first << " val: " << range.second->second << "\n";

    return 0;
}
