#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt1{1}, pt4{4};
    std::vector<Point> points(4);

    printSequentialContainer(points);
    
    std::fill(points.begin(), points.end(), pt4);
    printSequentialContainer(points);

    std::fill(std::next(points.begin(), 1), std::prev(points.end()), pt1);
    printSequentialContainer(points);

    return 0;
}
