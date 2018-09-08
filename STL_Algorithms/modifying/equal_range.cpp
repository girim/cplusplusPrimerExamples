#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4};
    std::vector<Point> points = {pt0, pt1, pt2, pt2, pt2, pt3, pt4};

    printSequentialContainer(points);
    auto result  = std::equal_range(points.begin(), points.end(), pt2);

    std::cout << "Begin: " << (result.first - points.begin()) << "\n";
    std::cout << "End: " << (result.second - points.begin()) << "\n";

    for(auto iter = result.first; iter != result.second; ++iter)
    {
        std::cout << *iter << "\n";
    }

    return 0;
}
