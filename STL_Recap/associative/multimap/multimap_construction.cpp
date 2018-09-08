#include <map>
#include <iostream>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    /* 1. empty multimap */
    std::multimap<Point, unsigned> points;
    Point pt{}, pt1{1, 1}, pt2{2, 2}, pt3{3, 3};
    points.emplace(pt1, 1);
    points.emplace(pt3, 2);
    points.emplace(pt, 3);
    points.emplace(pt2, 4);
    points.emplace(pt, 5);
    points.emplace(pt3, 6);

    printAssocContainer(points);

    /* 2. range */
    std::multimap<Point, unsigned> points_0(points.begin(), points.end());
    printAssocContainer(points_0);

    std::multimap<Point, unsigned> points_1(std::next(points.begin(), 2), std::prev(points.end()));
    printAssocContainer(points_1);

    /* 3. copy constructor */
    std::multimap<Point, unsigned> points_2(points_1);
    printAssocContainer(points_2);

    /* 4. move constructor */
    std::multimap<Point, unsigned> points_3(std::move(points_2));
    printAssocContainer(points_2);
    printAssocContainer(points_3);

    /* 5. initializer_list */
    std::multimap<Point, unsigned> points_4 = {{pt, 1}, {pt2, 2}, {pt3, 3}};
    printAssocContainer(points_4);

    std::multimap<Point, unsigned> points_5({{pt1, 1}, {pt2, 2}, {pt3, 3}});
    printAssocContainer(points_5);

    return 0;
}
