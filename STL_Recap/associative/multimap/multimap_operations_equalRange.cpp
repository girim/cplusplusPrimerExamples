#include <map>
#include <iostream>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1, 1}, pt2{2, 2}, pt3{3, 3};
    std::multimap<Point, unsigned> points;
    points.emplace(pt0, 1);
    points.emplace(pt2, 2);
    points.emplace(pt2, 3);
    points.emplace(pt3, 4);
    points.emplace(pt2, 5);
    points.emplace(pt1, 6);

    printAssocContainer(points);
    auto iter = points.equal_range(pt2);
    std::cout << "First Key: " << iter.first->first << " Value: " << iter.first->second << "\n"; 
    std::cout << "Last Key: " << iter.second->first << " Value: " << iter.second->second << "\n"; 

    auto lowbound =  points.lower_bound(pt2);
    std::cout << "lowbound: " << lowbound->first << " value: " << lowbound->second << "\n";

    auto upperbound = points.upper_bound(pt2);
    std::cout << "upperbound: " << upperbound->first << " value: " << upperbound->second << "\n";


    return 0;
}
