#include <iostream>
#include <forward_list>
#include "point.hpp"
#include "printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt, pt1(1, 1), pt2(2, 2), pt3(3, 3), pt4(4, 4);
    std::forward_list<Point> points = {pt, pt1, pt2, pt3, pt4};

    printSequentialContainer(points);
    auto size = std::distance(points.begin(), points.end());
    auto iter = points.erase_after(points.begin(), std::next(points.begin(), ( size - 1)));
    printSequentialContainer(points);
    std::cout << "element after the last elment deleted: " << *iter << std::endl;

    return 0;
}
