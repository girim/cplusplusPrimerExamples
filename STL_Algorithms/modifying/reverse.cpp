#include <iostream>
#include <vector>
#include <algorithm>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::vector<Point>  points = {pt0, pt1, pt2, pt3};

    printSequentialContainer(points);
    
    std::reverse(points.begin(), points.end());

    printSequentialContainer(points);

    return 0;
}
