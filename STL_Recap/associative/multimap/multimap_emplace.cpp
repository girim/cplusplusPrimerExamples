#include <iostream>
#include <map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    std::multimap<Point, std::string> points;
    Point pt0{}, pt1{1, 1}, pt2{2, 2}, pt3{3, 3};
    points.emplace(pt0, "C");
    points.emplace(pt1, "C++");
    points.emplace(pt2, "JavaScript");

    printAssocContainer(points);

    points.emplace_hint(points.end(), pt3, "Python");
    printAssocContainer(points);

    return 0;
}
