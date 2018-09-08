#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4}, pt5{5};
    std::vector<Point> points = {pt0, pt1, pt2, pt5, pt3, pt4};

    printSequentialContainer(points);

    auto iterTillSorted =  std::is_sorted_until(points.begin(), points.end());

    for(auto iter = points.begin(); iter != iterTillSorted; ++iter)
    {
        std::cout << *iter << "\n";
    }

    return 0;
}
