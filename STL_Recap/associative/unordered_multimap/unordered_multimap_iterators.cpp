#include <iostream>
#include <unordered_map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    /* unordered_multimap uses 'forward_iterators' */
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::unordered_multimap<Point, std::string, Point> points;

    points.emplace(pt0, "x");
    points.emplace(pt1, "y");
    points.emplace(pt1, "t");
    points.emplace(pt2, "z");
    points.emplace(pt3, "u");

    printAssocContainer(points);

    /* [begin, end) */
    for(std::unordered_multimap<Point, std::string, Point>::iterator iter = points.begin(); iter != points.end(); ++iter)
    {
        std::cout << "Key : " << iter->first << " Value: " << iter->second << "\n";
        /* cannot change the key as it is constant */
        if(iter->first == pt1)
        {
            iter->second = "null";
        }
    }
    std::cout << "\n";

    printAssocContainer(points);

    /* [cbegin, cend) */
    for(std::unordered_multimap<Point, std::string, Point>::const_iterator iter = points.cbegin(); iter != points.cend(); ++iter)
    {
        std::cout << "Key: " << iter->first <<  "Value: " << iter->second << "\n";
        if(iter->second == "null")
        {
            //iter->second = "g";
        }
    }    

    return 0;
}

