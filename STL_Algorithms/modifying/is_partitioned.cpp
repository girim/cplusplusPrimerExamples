#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1, 3}, pt2{2}, pt3{3, 5}, pt4{4};
    std::vector<Point> points = {pt0, pt2, pt4, pt3, pt1};
    std::vector<Point> points_0 = {pt0, pt2, pt4};

    printSequentialContainer(points);

    auto result =  std::is_partitioned(points.begin(), points.end(), [](const Point& point){
            return (point.getX() == point.getY());
    });

    std::cout << "is partitioned ? " << std::boolalpha << result << "\n";

    result = std::is_partitioned(points_0.begin(), points_0.end(), [](const Point& point){
            return (point.getX() == point.getY());
    });

    std::cout << "is partitioned ? " << std::boolalpha << result << "\n";

    return 0;
}
