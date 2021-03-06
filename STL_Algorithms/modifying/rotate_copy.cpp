#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::vector<Point> points = {pt0, pt1, pt2, pt3};
    std::vector<Point> points_0(4);

    printSequentialContainer(points);

    std::rotate_copy(points.begin(), points.begin()+1, points.end(), points_0.begin());
    printSequentialContainer(points_0);

    return 0;
}
