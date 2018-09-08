#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt3{3}, pt4{4}, pt2{2};
    std::vector<Point> points = {pt1, pt3, pt0, pt2, pt4};

    printSequentialContainer(points);
    /* Using default 'less than' predicate */
    std::sort(points.begin(), points.end());

    printSequentialContainer(points);

    /* Using custom predicate*/
    std::sort(points.begin(), points.end(), [](const Point& pt1, const Point& pt2){
            return (pt1 > pt2);
    });
    printSequentialContainer(points);

    return 0;
}
