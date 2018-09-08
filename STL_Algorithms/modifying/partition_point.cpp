#include <iostream>
#include <vector>
#include <algorithm>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2, 4}, pt3{3, 6}, pt4{4};
    std::vector<Point> points = {pt0, pt1, pt2, pt3, pt4};

    std::partition(points.begin(), points.end(), [](const Point &point) {
            return (point.getX() != point.getY());
    });

    auto partitionPoint = std::partition_point(points.begin(), points.end(), [](const Point &point) {
        return (point.getX() != point.getY());
    });

    printSequentialContainer(points);

    for(auto iter = points.begin(); iter != partitionPoint; ++iter)
    {
        std::cout << *iter << "\n";
    }

    return 0;
}
