#include <iostream>
#include <unordered_set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::unordered_set<Point, Point> point_0 = {pt0, pt2};
    std::unordered_set<Point, Point> point_1 = {pt1, pt3};

    printAssocContainer(point_0);
    printAssocContainer(point_1);

    point_0.swap(point_1);

    printAssocContainer(point_0);
    printAssocContainer(point_1);

    point_0.clear();
    point_1.clear();

    printAssocContainer(point_0);
    printAssocContainer(point_1);
    
    return 0;
}
