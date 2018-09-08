#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt8{8};
    std::vector<Point> points(5);

    printSequentialContainer(points);
    std::fill_n(points.begin()+1, 3, pt8);

    printSequentialContainer(points);

    return 0;
}
