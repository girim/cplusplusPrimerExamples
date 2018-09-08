#include <iostream>
#include <list>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt1(0, 1), pt2(0, 2), pt3(0, 3), pt4(0, 4);
    std::list<Point> points;
    points.push_back(pt1);
    points.push_back(pt2);
    printSequentialContainer(points);

    points.push_front(pt3);
    points.push_front(pt4);
    printSequentialContainer(points);

    points.pop_back();
    printSequentialContainer(points);

    points.pop_front();
    printSequentialContainer(points);

    return 0;
}

