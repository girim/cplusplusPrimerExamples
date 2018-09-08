#include <iostream>
#include <unordered_set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::unordered_set<Point, Point> points = {pt0, pt1, pt2, pt3};

    printAssocContainer(points);

    /* 1. erase by position */
    auto iter = points.erase(std::next(points.begin()));
    std::cout << "Item next to the erased item: " << *iter << "\n";
    printAssocContainer(points);

    /* 2. erase by key */
    size_t count = points.erase(pt0);
    std::cout << "No of elements deleted: " << count << "\n";

    /* 3. erase by Range */
    points.erase(points.begin(), points.end());
    printAssocContainer(points);

    return 0;
}
