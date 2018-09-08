#include <map>
#include <iostream>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1, 1}, pt2{2, 2}, pt3{3, 3};
    std::multimap<Point, unsigned> points = {{pt0, 1}, {pt1, 2}, {pt2, 3}, {pt1, 4}};
    printAssocContainer(points);

    auto iter = points.find(pt1);
    
    if(iter != points.end())
    {
        std::cout << "Found item: key: " << iter->first << " value: " << iter->second << "\n";
    }

    iter = points.find(pt3);
    if(iter == points.end())
    {
        std::cout << "item notfound: "  << "\n";
    }

    return 0;
}
