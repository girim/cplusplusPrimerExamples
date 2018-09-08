#include <iostream>
#include <vector>
#include <algorithm>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4}, pt5{5}, pt6{6};
    std::vector<Point> points = {pt6, pt5, pt4, pt3, pt0, pt2, pt1};

    printSequentialContainer(points);

    std::partial_sort(points.begin(), points.begin()+4, points.end());
    printSequentialContainer(points);

    std::partial_sort(points.begin(), points.begin()+4, points.end(), [](const Point& pt1, const Point& pt2){
            return (pt1 > pt2);
    });
    printSequentialContainer(points);

    return 0;
}
