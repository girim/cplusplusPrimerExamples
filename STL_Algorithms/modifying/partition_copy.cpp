#include <algorithm>
#include <vector>
#include <iostream>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2, 4}, pt3{3}, pt4{4, 8}, pt5{9,7};
    std::vector<Point> inputPoints = {pt0, pt1, pt2, pt3, pt4, pt5};
    std::vector<Point> partitionOne(3);
    std::vector<Point> partitionTwo(3);

    printSequentialContainer(inputPoints);

    auto result = std::partition_copy(inputPoints.begin(), inputPoints.end(), partitionOne.begin(), partitionTwo.begin(), [](const Point& point){
                return (point.getX() == point.getY());
    });

    printSequentialContainer(partitionOne);
    printSequentialContainer(partitionTwo);

    return 0;
}
