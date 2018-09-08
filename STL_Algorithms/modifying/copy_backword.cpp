#include <iostream>
#include <algorithm>
#include <vector>
#include "../printSeqContainer.hpp"
#include "../point.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::vector<Point> src{pt0, pt1, pt2, pt3};
    std::vector<Point> dst;
    dst.resize(src.size()+ 2);

    auto iter =  std::copy_backward(src.begin(), src.end(), dst.end());
    printSequentialContainer(dst);


    return 0;
}
