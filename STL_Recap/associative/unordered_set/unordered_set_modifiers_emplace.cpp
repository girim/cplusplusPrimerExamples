#include <iostream>
#include <unordered_set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::unordered_set<Point, Point> points;

    auto result  = points.emplace(pt3);
    std::cout << "insert result: inserted element: " << *result.first << " is success? " << result.second << "\n";

    points.emplace(pt0);
    points.emplace(pt1);

    printAssocContainer(points);

    result = points.emplace(pt0);
    std::cout << "insert result: item to inserted " << *result.first << " is success? " << result.second << "\n";

    auto iter =  points.emplace_hint(points.begin(), pt2);
    std::cout << "inserted element: " << *iter << "\n";
    printAssocContainer(points);

    return 0;
}
