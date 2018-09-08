#include <iostream>
#include <map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt{}, pt1{1, 1}, pt2{2, 2};
    std::map<Point, unsigned> points = {{pt, 1}, {pt1, 2}, {pt2, 3}};
    printAssocContainer(points);

    std::map<Point, unsigned>::iterator iter  = points.find(pt1);
    
    if(iter != points.end())
    {
        std::cout << "Found item : key: " << iter->first << " value: " << iter->second << "\n";
    }

    Point pt4{4, 4};
    iter = points.find(pt4);
    if(iter == points.end())
    {
        std::cout << "Item is not found...." << "\n";
    }

    return 0;
}