#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::vector<Point> points_0(5);
    std::vector<Point> points_1 = {pt0, pt1, pt2, pt3};

    std::cout << "Before swap: " << "\n";
    printSequentialContainer(points_0);
    printSequentialContainer(points_1);

    std::iter_swap(points_0.begin(), std::next(points_1.begin(), 3));

    std::cout << "After swap: " << "\n";
    printSequentialContainer(points_0);
    printSequentialContainer(points_1);

    return 0;
}
