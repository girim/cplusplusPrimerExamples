#include <iostream>
#include <forward_list>
#include "point.hpp"
#include "printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt{}, pt1{1, 1}, pt2{2, 2}, pt3{3, 3}, pt4{4, 4};
    std::forward_list<Point> points_0 = {pt, pt2, pt4};
    std::forward_list<Point> points_1 = {pt1, pt3};

    printSequentialContainer(points_0);
    printSequentialContainer(points_1);

    points_0.merge(points_1);
    printSequentialContainer(points_0);
    printSequentialContainer(points_1);

    return 0;
}
