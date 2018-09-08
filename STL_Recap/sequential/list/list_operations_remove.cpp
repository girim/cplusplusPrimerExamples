#include <iostream>
#include <list>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    std::list<Point> points(4);
    printSequentialContainer(points);

    Point pt;
    points.remove(pt);
    printSequentialContainer(points);

    return 0;
}
