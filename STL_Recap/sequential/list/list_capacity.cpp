#include <iostream>
#include <list>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    std::list<Point> points;
    std::cout << "Is list empty? " << (points.empty() ? "yes":  "no") << std::endl;

    Point pt;
    points.push_back(pt);
    printSequentialContainer(points);

    std::cout << "size of points: " << points.size() <<  "\n";
    std::cout << "maz size of points: " << points.max_size() << "\n";

    return 0;
}
