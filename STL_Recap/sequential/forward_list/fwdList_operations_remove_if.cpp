#include <iostream>
#include <forward_list>
#include "point.hpp"
#include "printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt{}, pt1{1, 3}, pt2{2, 4}, pt3{7, 9}, pt4{8, 10}, pt5{2, 1}, pt6{4, 3}, pt7{8, 7};
    std::forward_list<Point> points = {pt, pt1, pt2, pt3, pt4, pt5, pt6, pt7};
    printSequentialContainer(points);

    points.remove_if([](const Point& pt){
        return (pt.getX() % 2 == 0 && pt.getY() % 2 == 0);
    });
    printSequentialContainer(points);

    points.remove_if([](const Point& pt){
        return (pt.getX() % 2 == 0 && pt.getY() % 2 != 0);
    });
    printSequentialContainer(points);

    return 0;
}
