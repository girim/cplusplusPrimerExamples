#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::vector<Point> points = {pt0, pt1, pt0, pt2};

    printSequentialContainer(points);
    std::replace_copy(points.begin(), points.end(), points.begin(), pt0, pt3);
    printSequentialContainer(points);

    return 0;
}
