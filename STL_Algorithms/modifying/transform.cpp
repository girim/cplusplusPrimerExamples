#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::vector<Point> points = {pt0, pt1, pt2, pt3};
    std::vector<Point> points_1(points.size());

    printSequentialContainer(points);
    std::transform(points.begin(), points.end(), points.begin() ,[](Point point){
        return ++point;
    });
    printSequentialContainer(points);

    printSequentialContainer(points_1);
    std::transform(points.begin(), points.end(), points_1.begin(), points_1.begin(), [](Point pt1, Point pt2){
        return pt1 + pt2;
    });
    printSequentialContainer(points_1);

    return 0;
}
