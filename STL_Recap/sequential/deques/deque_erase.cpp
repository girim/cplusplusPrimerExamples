#include <iostream>
#include <deque>
#include "point.hpp"
#include "printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt1(1, 1), pt2(3, 4), pt3(1,4);
    std::deque<Point> points = {pt1, pt2, pt3};
    printSequentialContainer(points);

    points.push_back(pt3);
    points.push_back(pt1);
    printSequentialContainer(points);

    auto iter = points.erase(points.begin());
    printSequentialContainer(points);

    iter =  points.erase(points.begin()+1, points.begin()+3);
    printSequentialContainer(points);

    return 0;
}
