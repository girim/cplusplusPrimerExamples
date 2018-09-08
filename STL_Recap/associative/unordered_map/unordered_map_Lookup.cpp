#include <iostream>
#include <unordered_map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::unordered_map<std::string, Point> points = {{"one", pt0}, {"two", pt1}, {"three", pt2}, {"four", pt3}};

    printAssocContainer(points);

    /* 1. find --> returns iterator to found item */
    std::unordered_multimap<std::string, Point>::iterator iter  = points.find("four");

    if(iter != points.end())
    {
        std::cout << "Element found: key: " << iter->first << " value: " << iter->second << '\n';
    }

    std::unordered_map<Point, std::string, Point> points_0 = {{pt0, "one"}, {pt1, "two"}, {pt2, "three"}};
    auto it = points_0.find(pt2);

    if(it != points_0.end())
    {
        std::cout << "Element found: Key: " << it->first << " Value: " << it->second << "\n";
    }

    it =points_0.find(pt3);
    if(it == points_0.end())
    {
        std::cout << "Key not found" << "\n";
    }

    /* 2. count --> returns the no elements found per key */
    size_t noOfElementsWithSameKey  = points_0.count(pt0);
    std::cout << "Number of elements with key: " << noOfElementsWithSameKey << "\n";

    noOfElementsWithSameKey = points_0.count(pt3);
    std::cout << "Number of elements with key: " << noOfElementsWithSameKey << "\n";

    /* 3. equal_range */
    auto itr = points_0.equal_range(pt2);
    std::cout << "lowerBound: " << itr.first->first << "\n";
    std::cout << "upperBound: " << itr.second->first << "\n";

    return 0;
}

