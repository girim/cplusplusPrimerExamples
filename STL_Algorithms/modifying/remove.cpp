#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::vector<Point> points = {pt0, pt1, pt2, pt3, pt0, pt1, pt0};

    printSequentialContainer(points);

    /* returns the new end */
    auto end = std::remove(points.begin(), points.end(), pt0);

    for(auto iter = points.begin(); iter != end; ++iter)
    {
        std::cout << *iter << "\n";
    }

    return 0;
}
