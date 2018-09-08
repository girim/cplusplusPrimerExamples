#include <iostream>
#include <unordered_set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};

    /* 1. empty constructor */
    std::unordered_set<Point, Point>  points;
    printAssocContainer(points);

    /* 2. initializer_list */
    std::unordered_set<Point, Point> points_0 = {pt0, pt1, pt2, pt3};
    printAssocContainer(points_0);

    /* 3. Range */
    std::unordered_set<Point, Point> points_1(points_0.begin(), points_0.end());
    printAssocContainer(points_1);

    /* 4. copy constructor */
    std::unordered_set<Point, Point> points_2(points_1);
    printAssocContainer(points_2);

    /* 5. move constructor */
    std::unordered_set<Point, Point> points_3(std::move(points_2));
    printAssocContainer(points_2);
    printAssocContainer(points_3);

    return 0;
}
