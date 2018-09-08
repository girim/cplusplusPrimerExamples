#include <iostream>
#include <deque>
#include "point.hpp"
#include "printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt1, pt2(1, 1), pt3(2, 2), pt4(3, 3);
    std::deque<Point> points;
    points.push_back(pt1);
    printSequentialContainer(points);

    points.push_back(pt1);
    points.push_front(pt2);
    printSequentialContainer(points);

    points.push_back(pt3);
    printSequentialContainer(points);

    points.push_front(pt4);
    printSequentialContainer(points);

    points.pop_back();
    printSequentialContainer(points);

    points.pop_front();
    printSequentialContainer(points);

    return 0;
}


