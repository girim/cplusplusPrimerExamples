#include <iostream>
#include <list>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt1(1,1), pt2(1, 4), pt3(3, 5), pt4(8, 9);
    std::list<Point> points = {pt1, pt2, pt3, pt4};

    printSequentialContainer(points);

    points.remove_if([](const Point& pt){
        return (pt.getX() == 1 && pt.getY() == 1);
    });

    printSequentialContainer(points);


    return 0;
}
