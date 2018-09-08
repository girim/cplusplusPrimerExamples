#include <iostream>
#include <vector>
#include <algorithm>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4};
    std::vector<Point> points = {pt0, pt1, pt2, pt3, pt4};

    printSequentialContainer(points);

    auto iter = std::upper_bound(points.begin(), points.end(), pt2);
    std::cout << "Upper bound of " << pt2 << " is: " << *iter << "\n";
    
    return 0;
}
