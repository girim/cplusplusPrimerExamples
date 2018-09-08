#include <iostream>
#include <unordered_map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4};
    std::unordered_map<Point, unsigned, Point> points = {{pt0, 10}, {pt1, 20}, {pt2, 30}};
    printAssocContainer(points);
    
    /* Using key */
    size_t numOfItemsDeleted = points.erase(pt1);
    std::cout << "Number of elements deleted: " << numOfItemsDeleted << "\n";
    printAssocContainer(points);

    /* Using position */
    auto iter = points.erase(points.begin());
    std::cout << "Item next to deleted one is,  Key: " << iter->first << " Value: " << iter->second << "\n"; 
    printAssocContainer(points);

    points.emplace(pt1, 30);
    points.emplace(pt2, 40);
    points.emplace(pt3, 50);
    points.emplace(pt4, 60);

    printAssocContainer(points);

    /* Using range */
    iter = points.erase(std::next(points.begin()), std::next(points.begin(), 3));
    printAssocContainer(points);
    std::cout << "iter points to : " << iter->first << " " << iter->second << "\n";

    return 0;
}
