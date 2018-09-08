#include <iostream>
#include <list>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt1(1, 1), pt2(4, 4), pt4(6, 6);
    Point pt5(2, 2), pt6(3, 3), pt7(5, 5); 

    std::list<Point> points_0 = {pt1, pt2, pt4};
    std::list<Point> points_1 = {pt5, pt6, pt7};

    points_1.merge(points_0);
    printSequentialContainer(points_1);

    return 0;
}
