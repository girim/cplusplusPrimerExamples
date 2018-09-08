#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{0, 2}, pt1{3, 4}, pt2{4, 3}, pt3{8, 9}, pt4{8, 2};
    std::vector<Point> points = {pt0, pt3, pt2, pt1, pt4};

    printSequentialContainer(points);
    std::stable_sort(points.begin(), points.end(), [](const Point& pt1, const Point& pt2){
            return ((pt1.getX()+pt1.getY()) > (pt2.getX() + pt2.getY()));
    });

    printSequentialContainer(points);

    return 0;
}
