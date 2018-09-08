#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{};
    std::vector<Point> points(6);

    printSequentialContainer(points);

    std::generate(points.begin(), points.end(), [&pt0](){
        return ++pt0;
    });

    printSequentialContainer(points);

    return 0;
}
