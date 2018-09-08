#include <iostream>
#include <list>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    std::list<Point> points;
    auto iter = points.emplace(points.begin(), 4, 6);
    std::cout << "Just emplaced element is : " << *iter << std::endl;

    printSequentialContainer(points);

    points.emplace_front(2, 2);  //emplace_front does not return anything
    printSequentialContainer(points);

    points.emplace_back(1, 1);   //emplace_back does not return anything
    printSequentialContainer(points);

    return 0;
}

