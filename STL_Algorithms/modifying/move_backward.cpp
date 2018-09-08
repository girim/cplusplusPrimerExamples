#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::vector<Point> points_0 = {pt1, pt2, pt3, pt0};
    std::vector<Point> points_1(points_0.size() + 1);

    printSequentialContainer(points_0);
    printSequentialContainer(points_1);

    auto iter = std::move_backward(points_0.begin(), points_0.end(), points_1.end());
    printSequentialContainer(points_1);

    return 0;
}
