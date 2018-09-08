#include <iostream>
#include <list> 
#include <iterator>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    std::list<Point> points;
    /* 1. fill */
    Point pt(3, 4);
    points.assign(4, pt);
    printSequentialContainer(points);

    /* 2. range */ 
    std::list<Point> points_0;
    auto iter = points.begin();
    std::advance(iter , 2);
    points_0.assign(iter, points.end());
    printSequentialContainer(points_0);

    /* 3. initializer_list */
    std::list<Point> points_1;
    points_1.assign({pt, pt});
    printSequentialContainer(points_0);

    return 0;
}
