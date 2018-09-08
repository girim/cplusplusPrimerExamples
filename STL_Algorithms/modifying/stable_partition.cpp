#include <iostream>
#include <vector>
#include <algorithm>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1, 3}, pt2{2}, pt3{3, 4}, pt4{4}, pt5{6, 7};
    std::vector<Point> points = {pt0, pt1, pt2, pt3, pt4, pt5};

    printSequentialContainer(points);

    /* stable_partition presever the order */
    auto result =  std::stable_partition(points.begin(), points.end(), [](const Point& point){
            return (point.getX() == point.getY());
    });

    printSequentialContainer(points);

    return 0;
}
