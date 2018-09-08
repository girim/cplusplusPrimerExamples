#include <set>
#include <iostream>
#include "../printAssociativeContainer.hpp"
#include "../point.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2};
    /* 1. empty constructor */
    std::set<Point> points;

    /* 2. initializer_list */
    std::set<Point> points_0 = {pt1, pt2, pt0};
    printAssocContainer(points_0);

    /* 3. range constructor */
    std::set<Point> points_1(points_0.begin(), points_0.end());
    printAssocContainer(points_1);

    /* 4. copy constructor */
    std::set<Point> points_2(points_1);
    printAssocContainer(points_1);

    /* 5. move constructor */
    std::set<Point> points_3(std::move(points_2));
    printAssocContainer(points_2);
    printAssocContainer(points_3);

    return 0;
}
