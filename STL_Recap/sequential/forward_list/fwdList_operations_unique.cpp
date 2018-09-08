#include <iostream>
#include <forward_list>
#include "point.hpp"
#include "printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt{}, pt1{1, 1}, pt2{2, 2}, pt3{3, 3};
    std::forward_list<Point> points = {pt, pt, pt1, pt2, pt2, pt2, pt3, pt, pt3, pt3};
    printSequentialContainer(points);

    points.unique();
    printSequentialContainer(points);

    points.sort();
    printSequentialContainer(points);
    points.unique();
    printSequentialContainer(points);

    return 0;
}
