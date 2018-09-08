#include <iostream>
#include <vector>
#include <algorithm>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4}, pt5{5}, pt6{6};
    std::vector<Point> points = {pt0, pt1, pt4, pt3, pt2, pt5, pt6};
    std::vector<Point> result(4);

    printSequentialContainer(points);
    

    std::partial_sort_copy(points.begin(), points.begin()+4,  result.begin(), result.end());

    printSequentialContainer(result);

    return 0;
}
