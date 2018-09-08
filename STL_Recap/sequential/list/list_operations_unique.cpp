#include <iostream>
#include <list>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt, pt1(8, 9), pt2(3, 4);
    std::list<Point> points(3, pt);
    points.push_back(pt2);
    points.push_back(pt2);
    points.push_back(pt1);
    points.push_back(pt1);

    printSequentialContainer(points);

    points.unique();
    printSequentialContainer(points);

    points.unique([](const Point& lhs, const Point& rhs){
        return (lhs.getX()+ 5 == rhs.getX());
    });
    printSequentialContainer(points);

    return 0;
}
