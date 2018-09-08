#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2, 3}, pt3{5, 6}, pt4{4};
    std::vector<Point> points = {pt0, pt1, pt2, pt3, pt4};

    printSequentialContainer(points);

    auto begin  = std::partition(points.begin(), points.end(), [](const Point& point){
            return (point.getX() != point.getY());
    });

    printSequentialContainer(points);

    return 0;
}
