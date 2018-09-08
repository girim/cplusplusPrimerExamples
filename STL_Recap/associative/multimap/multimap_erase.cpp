#include <map>
#include <iostream>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1, 1}, pt2{2, 2}, pt3{3, 3};
    std::multimap<Point, unsigned> points = {{pt0, 1}, {pt1, 2}, {pt3, 3},{pt0, 4}};
    printAssocContainer(points);

    /* 1. erase using key */
    auto numOfElementsErased = points.erase(pt0);
    std::cout << "Number of elements erased: " << numOfElementsErased << "\n";
    printAssocContainer(points);

    /* 2. erase using iterator(position) */
    //auto iter = points.erase(std::prev(points.end()));
    auto iter = points.erase(points.begin());
    std::cout << "erased element[returns iter to next element]: " << iter->first << " " << iter->second << "\n";
    printAssocContainer(points);

    points.emplace(pt0, 3);
    points.emplace(pt2, 4);
    points.emplace(pt1, 5);
    points.emplace(pt3, 6);

    printAssocContainer(points);
    /* 3. erase using range */
    auto it = points.erase(std::next(points.begin()), std::prev(points.end(), 1));
    std::cout << "erased element[returns iter to last element erased]: " << it->first << " " << it->second << "\n";

    printAssocContainer(points);

    return 0;
}
