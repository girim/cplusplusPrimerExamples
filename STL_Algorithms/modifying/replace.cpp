#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4};
    std::vector<Point> points = {pt0, pt1, pt0, pt2, pt3};

    printSequentialContainer(points);

    /* Replace all occurences of pt0 with pt4 */
    std::replace(points.begin(), points.end(), pt0, pt4);
    printSequentialContainer(points);

    return 0;
}
