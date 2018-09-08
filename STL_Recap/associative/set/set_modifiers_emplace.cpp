#include <iostream>
#include <set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::set<Point> points;

    auto result = points.emplace(pt0);
    std::cout << "Element inserted key/value: " << *result.first << " is successful: " << result.second << "\n";

    points.emplace(pt1);
    points.emplace(pt2);

    printAssocContainer(points);

    points.emplace_hint(std::prev(points.end()), pt3);
    printAssocContainer(points);

    return 0;
}
