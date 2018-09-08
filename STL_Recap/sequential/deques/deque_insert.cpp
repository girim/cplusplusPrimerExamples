#include <iostream>
#include <deque>
#include "point.hpp"
#include "printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    /* 1. insert single element */
    std::deque<Point> points;

    Point pt;
    
    std::deque<Point>::iterator iter  = points.insert(points.cbegin(), pt);
    std::cout << "First element inserted is : " << *iter << "\n";

    printSequentialContainer(points);

    /* 2. fill */
    points.insert(points.cbegin(), 2, pt);
    printSequentialContainer(points); 

    /* 3. range */
    std::deque<Point> points_1;
    points_1.insert(points_1.begin(), points.begin(), points.end());
    printSequentialContainer(points_1);

    /* 4. initializer_list */
    std::initializer_list<Point> pts = {std::move(pt), std::move(pt), pt};
    points.insert(points.end(), pts);
    printSequentialContainer(points);

    /* 5. move */
    Point center(9, 9);
    points.insert(points.begin(), std::move(center));
    printSequentialContainer(points);

    return 0;
}
