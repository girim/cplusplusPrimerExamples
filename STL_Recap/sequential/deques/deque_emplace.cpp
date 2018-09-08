#include <iostream>
#include <deque>
#include "printSeqContainer.hpp"
#include "point.hpp"

int main(int argc, char const *argv[])
{
    std::deque<Point> points;
    auto iter  = points.emplace(points.begin(), 10, 40);

    printSequentialContainer(points);
    std::cout << "The iter is : " << *iter << std::endl;

    points.emplace_back(20, 90);
    printSequentialContainer(points);

    points.emplace_front(3, 4);
    printSequentialContainer(points);

    return 0;
}
