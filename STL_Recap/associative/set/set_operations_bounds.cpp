#include <iostream>
#include <set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::set<Point> points = {pt0, pt2, pt1, pt3};

    printAssocContainer(points);

    auto lowerBound = points.lower_bound(pt2);
    auto upperBound = points.upper_bound(pt2);
    auto range = points.equal_range(pt2);

    std::cout << "lowerBound: " << *lowerBound << "\n";
    std::cout << "upperBound: " << *upperBound << "\n";
    std::cout << "equalRange:[ " << *range.first << " , " << *range.second << " ]" << "\n"; 

    return 0;
}
