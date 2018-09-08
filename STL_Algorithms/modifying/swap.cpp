#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};

    std::swap(pt0, pt3);
    std::cout << "After swap: pt0: " << pt0 << "  pt3: " << pt3 << "\n";

    std::vector<Point> points_1 = {pt0, pt2};
    std::vector<Point> points_2 = {pt1, pt3};

    printSequentialContainer(points_1);
    printSequentialContainer(points_2);

    std::swap(points_1, points_2);

    std::cout << "After swap: " << "\n";
    printSequentialContainer(points_1);
    printSequentialContainer(points_2);

    return 0;
}
