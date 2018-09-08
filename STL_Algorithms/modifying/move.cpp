#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::vector<Point> points_0 = {pt0, pt1, pt2, pt3};
    std::vector<Point> points_1(4);

    printSequentialContainer(points_0);

    /* Moving elements */
    auto iter  = std::move(points_0.begin(), points_0.end(), points_1.begin());

    printSequentialContainer(points_1);
    printSequentialContainer(points_0);

    /* Moving container */
    points_1 = std::move(points_0);
    printSequentialContainer(points_1);
    printSequentialContainer(points_0);

    return 0;
}
