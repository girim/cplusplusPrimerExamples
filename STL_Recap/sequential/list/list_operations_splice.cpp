#include <iostream>
#include <list>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    /* 1. entire list */
    Point pt1(2, 4);
    std::list<Point> dst(2, pt1);
    std::list<Point> src(4);
 
    dst.splice(dst.end(), src);
    printSequentialContainer(dst);
    printSequentialContainer(src);

    /* 2. sigle element */
    std::list<Point> points;
    points.splice(points.begin(), dst, dst.begin());
    printSequentialContainer(points);
    printSequentialContainer(dst);

    /* 3. range */
    std::list<Point> finalList;
    finalList.splice(finalList.begin(), dst, std::next(dst.begin(), 2), dst.end());
    printSequentialContainer(dst); 
    printSequentialContainer(finalList);
    

    return 0;
}
