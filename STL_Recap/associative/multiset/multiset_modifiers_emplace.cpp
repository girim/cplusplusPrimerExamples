#include <iostream>
#include <set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::multiset<Point> points;

    auto iter = points.emplace(pt0);
    std::cout << "Emplaced element is : " << *iter << "\n";
    printAssocContainer(points);

    points.emplace(pt1);
    points.emplace(pt2);
    printAssocContainer(points);

    points.emplace_hint(points.end(), pt3);
    printAssocContainer(points);

    return 0;
}
