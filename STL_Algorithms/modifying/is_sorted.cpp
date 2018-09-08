#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4};
    std::vector<Point> points = {pt2, pt1, pt3, pt0, pt4};

    printSequentialContainer(points);
    std::cout << "Is sorted: " << std::boolalpha << std::is_sorted(points.begin(), points.end()) << "\n";

    std::sort(points.begin(), points.end());
    printSequentialContainer(points);
    std::cout << "Is sorted: " << std::boolalpha << std::is_sorted(points.begin(), points.end()) << "\n";


    return 0;
}
