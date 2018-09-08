#include <iostream>
#include <forward_list>
#include "point.hpp"
#include "printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    std::forward_list<Point> points;
    Point pt, pt1(1, 1);
    points.push_front(pt);
    printSequentialContainer(points);

    points.push_front(pt1);
    points.push_front(pt1);
    printSequentialContainer(points);

    points.pop_front();
    printSequentialContainer(points);


    return 0;
}
