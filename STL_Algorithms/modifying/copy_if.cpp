#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1, 4}, pt2{2, 5}, pt3{3}, pt4{3, 5};
    std::vector<Point> src{pt0, pt1, pt2, pt3, pt4};
    std::vector<Point> dst;
    dst.resize(src.size());

    /* copy if x != y */
    auto iter = std::copy_if(src.begin(), src.end(), dst.begin(), [](const Point& point){
            return (point.getX() != point.getY());
    });
    dst.resize(std::distance(dst.begin(), iter));

    printSequentialContainer(src);
    printSequentialContainer(dst);

    return 0;
}
