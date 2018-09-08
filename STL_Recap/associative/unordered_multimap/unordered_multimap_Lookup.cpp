#include <unordered_map>
#include <iostream>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4};
    std::unordered_multimap<Point, std::string, Point> points = {{pt0, "India"}, {pt1, "US"}, {pt2, "Germany"}};
    points.emplace(pt3, "Austria");
    points.emplace(pt2, "Czech");
    points.emplace(pt2, "Slovakia");

    printAssocContainer(points);

    /* 1. find with key--> returns iter to found item else returns .end() */
    auto iter  = points.find(pt2);
    
    if(iter != points.end())
    {
        std::cout << "item found with key: " << iter->first << " Value: " << iter->second << "\n";
    }

    iter = points.find(pt4);
    if(iter == points.end())
    {
        std::cout << "item not found: " << "\n";
    }

    /* 2. count the key or to find element exist in the container or not */
    size_t noOfElementsWithSameKey  = points.count(pt2);
    std::cout << "No of elements with same key: " << noOfElementsWithSameKey << "\n";

    noOfElementsWithSameKey = points.count(pt4);
    std::cout << "No of elements with same key: " << noOfElementsWithSameKey << "\n";

    noOfElementsWithSameKey = points.count(pt0);
    std::cout << "No of elements with same key: " << noOfElementsWithSameKey << "\n";

    /* equal range iter<lower, upper> */
    auto result =  points.equal_range(pt2);
    std::cout << "LowerBound: key:  " << result.first->first << " value: " << result.first->second << "\n";
    std::cout << "UpperBound: Value: " << result.second->first << " value: " << result.second->second << "\n";

    for(auto iter = result.first; iter != result.second; ++iter)
    {
        std::cout << "key: " << iter->first << " value: " << iter->second << "\n";
    }

    return 0;
}
