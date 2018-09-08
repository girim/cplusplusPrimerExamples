#include <iostream>
#include <vector>
#include <algorithm>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::vector<Point> points = {pt0, pt0, pt1, pt2, pt2, pt3, pt2, pt2};

    printSequentialContainer(points);
    auto new_end  = std::unique(points.begin(), points.end());

    for(auto iter = points.begin(); iter != new_end; ++iter)
    {
        std::cout << *iter << "\n";
    }
    
    return 0;
}
