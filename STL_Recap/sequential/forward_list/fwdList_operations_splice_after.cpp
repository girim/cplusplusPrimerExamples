#include <iostream>
#include <forward_list>
#include "point.hpp"
#include "printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt, pt1(1, 1), pt2(2, 2), pt3(3, 3), pt4(4, 4);
    std::forward_list<Point> points = {pt, pt1, pt2, pt3, pt4};
    printSequentialContainer(points);

    /* 1. join(splice) entire list */
    std::forward_list<Point> points_0;
    points_0.splice_after(points_0.before_begin(), points);
    printSequentialContainer(points_0);
    printSequentialContainer(points);

    /* 2. join(splice) single element */
    std::forward_list<Point> points_1;
    points_1.splice_after(points_1.before_begin(), points_0, points_0.cbegin());
    printSequentialContainer(points_1);

    /* 3. join(splice) range of elements */
    printSequentialContainer(points_0);
    std::forward_list<Point> points_2;
    auto size = std::distance(points_0.begin(), points_0.end());
    points_2.splice_after(points_2.before_begin(), points_0, points_0.begin(), std::next(points_0.begin(), size-1));
    printSequentialContainer(points_2);

    return 0;
}
