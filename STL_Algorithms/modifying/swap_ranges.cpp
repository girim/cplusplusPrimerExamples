#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt4{4};
    std::vector<Point> points_1(8, pt0);
    std::vector<Point> points_2(8, pt4);

    printSequentialContainer(points_1);
    printSequentialContainer(points_2);

    std::swap_ranges(points_1.begin()+1, points_1.end()-1, points_2.begin());

    printSequentialContainer(points_1);
    printSequentialContainer(points_2);

    return 0;
}
