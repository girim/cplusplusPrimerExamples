#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    Point points[] = {pt0, pt1, pt2, pt3};

    std::vector<Point> copyOfPoints(5);
    auto iter = std::copy(std::begin(points), std::end(points), copyOfPoints.begin());

    printSequentialContainer(copyOfPoints);
    std::cout << "next to last copied position: " << (iter - copyOfPoints.begin()) << "\n";

    std::deque<Point> points_0(3);
    std::copy(copyOfPoints.begin(), copyOfPoints.end(), points_0.begin());
    printSequentialContainer(points_0);

    return 0;
}
