#include <iostream>
#include <set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::multiset<Point> points = {pt1, pt0, pt2, pt3};

    printAssocContainer(points);

    /* 1. erase by position */
    auto iter = points.erase(std::next(points.begin()));
    printAssocContainer(points);
    std::cout << "Next element to be deleted is : " << *iter << "\n";

    /* 2. erase by key/value */
    size_t count =  points.erase(pt2);
    std::cout << "Number of elements deleted: " << count << "\n";

    /* 3. erase by range */
    points.erase(points.begin(), points.end());
    printAssocContainer(points);

    return 0;
}
