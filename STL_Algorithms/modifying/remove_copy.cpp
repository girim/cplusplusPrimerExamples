#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::vector<Point> points = {pt0, pt1, pt2, pt3, pt0};
    std::vector<Point> points_1(3);

    printSequentialContainer(points);

    std::remove_copy(points.begin(), points.end(), points_1.begin(), pt0);
    
    printSequentialContainer(points);
    printSequentialContainer(points_1);

    return 0;
}
