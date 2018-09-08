#include <unordered_map>
#include <iostream>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4};
    /* 1. using empty constructor */
    std::unordered_multimap<Point, unsigned, Point> points;

    points.emplace(pt0, 10);
    points.emplace(pt1, 20);
    points.emplace(pt2, 30);
    points.emplace(pt3, 40);
    points.emplace(pt4, 50);
    points.emplace(pt4, 70);
    points.emplace(pt0, 80);

    printAssocContainer(points);

    /* 2. range constructor*/
    std::unordered_multimap<Point, unsigned, Point> copyOfPoints(points.begin(), points.end());
    printAssocContainer(points);

    /* 3. using copy constructor */
    std::unordered_multimap<Point, unsigned, Point> points_0(points);
    printAssocContainer(points_0);

    /* 4. using move constructor */
    std::unordered_multimap<Point, unsigned, Point> points_1(std::move(points_0));
    printAssocContainer(points_0);
    printAssocContainer(points_1);

    /* 5. using initializer_list */
    std::unordered_multimap<Point, unsigned, Point> points_2 = {{pt0, 11}, {pt1, 12}, {pt2, 13}};
    printAssocContainer(points_2);

    return 0;
}
