#include <iostream>
#include <forward_list>
#include "point.hpp"
#include "printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    std::forward_list<Point> points(2);
    printSequentialContainer(points);
    
    Point pt;
    points.remove(pt);
    printSequentialContainer(points);

    return 0;
}
