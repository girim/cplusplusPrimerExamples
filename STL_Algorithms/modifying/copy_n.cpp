#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4};
    Point points[] = {pt0, pt1, pt2, pt3, pt4};

    std::vector<Point> list;
    list.resize(6);

    auto iter  =  std::copy_n(std::begin(points), 5, list.begin());
    printSequentialContainer(list);

    return 0;
}
