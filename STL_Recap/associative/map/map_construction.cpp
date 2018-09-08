#include <map>
#include <iostream>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"


int main(int argc, char const *argv[])
{
    /* 1. empty map */
    std::map<unsigned, Point> points;
    Point pt, pt1{1, 1}, pt2{2, 2};
    points[2] = pt2;
    points[1] = pt1;
    points[0] = pt;

    printAssocContainer(points);
    /* 2. range */
    std::map<unsigned, Point> points_0(std::next(points.begin(), 1), std::prev(points.end()));
    printAssocContainer(points_0);

    /* 3. copy constructor */
    std::map<unsigned, Point> points_1(points_0);
    printAssocContainer(points_1);

    /* 4. move constructor */
    std::map<unsigned, Point> points_2(std::move(points_1));
    printAssocContainer(points_1);
    printAssocContainer(points_2);

    /* 5. initializer_list */
    std::map<unsigned, Point> points_3({{1, pt},{0, pt2}});
    printAssocContainer(points_3);


    return 0;
}
