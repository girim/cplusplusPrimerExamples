#include <iostream>
#include <list>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt1(4, 5), pt2(6, 7), pt3(1, 3), pt4(1, 2);
    std::list<Point> points = { pt1, pt2, pt3, pt4};

    printSequentialContainer(points);

    points.sort();
    printSequentialContainer(points);

    points.sort([](const Point& lhs, const Point& rhs){
        return (lhs > rhs);
    });
    printSequentialContainer(points);

    
    return 0;
}
