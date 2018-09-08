#include <iostream>
#include <list>
#include <iterator>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    std::list<Point> points(5);
    printSequentialContainer(points);

    auto iter = points.erase(points.begin());
    std::cout << "position next to just removed element: " << *iter << std::endl;
    printSequentialContainer(points);

    points.erase(std::next(points.begin()), points.end());
    printSequentialContainer(points);

    return 0;
}
