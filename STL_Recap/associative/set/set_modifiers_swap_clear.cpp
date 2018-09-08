#include <iostream>
#include <set>
#include <functional>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::set<Point> points_0 = {pt1, pt2};
    std::set<Point> points_1 = {pt0, pt3};
    /* std::set<Point, std::function<bool(const Point&, const Point&)>> points_1([](const Point& pt1, const Point& pt2){
        return (pt1 > pt2);
    });
    points_1.emplace(pt0, pt3); */

    printAssocContainer(points_0);
    printAssocContainer(points_1);

    points_0.swap(points_1);

    printAssocContainer(points_0);
    printAssocContainer(points_1);

    points_1.clear();
    printAssocContainer(points_1);

    return 0;
}
