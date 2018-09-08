#include <set>
#include <iostream>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::set<Point> points = {pt3, pt1, pt0, pt2};
    printAssocContainer(points);

    /* erase by --position */
    auto iter  = points.erase(std::next(points.begin(), 2));
    std::cout << "iterator to the immediate next element to be deleted is : " << *iter << "\n";
    printAssocContainer(points);

    /* erase by --key */
    size_t noOfItemsDeleted = points.erase(pt1);
    std::cout << "no of items deleted is: " << noOfItemsDeleted << "\n";
    printAssocContainer(points);

    /* erase by --range */
    iter = points.erase(points.begin(), points.end());
    printAssocContainer(points);


    return 0;
}
