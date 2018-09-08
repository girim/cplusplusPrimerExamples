#include <iostream>
#include <set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4};
    std::set<Point> points = {pt1, pt0, pt2, pt3};

    size_t noOfItem = points.count(pt3);
    std::cout << "Item count is : " << noOfItem << "\n";

    noOfItem = points.count(pt4);
    std::cout << "Item count is : " << noOfItem << "\n";

    return 0;
}
