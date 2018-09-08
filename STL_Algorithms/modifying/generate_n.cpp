#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt9{9};
    std::vector<Point> points(5);

    printSequentialContainer(points);
    std::generate_n(points.begin(), 5, [&pt9](){
        return --pt9;
    });
    printSequentialContainer(points);

    return 0;
}
