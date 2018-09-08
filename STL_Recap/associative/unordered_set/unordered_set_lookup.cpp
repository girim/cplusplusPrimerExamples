#include <iostream>
#include <unordered_set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4};
    std::unordered_set<Point, Point> points = {pt0, pt1, pt2, pt2, pt3};

    printAssocContainer(points);

    /* 1. find --> returns iterator to found item */
    std::unordered_set<Point, Point>::iterator iter = points.find(pt2);

    if(iter != points.end())
    {
        std::cout << "Found item is : " << *iter << "\n";
    }

    iter = points.find(pt4);
    if(iter == points.end())
    {
        std::cout << "Item no found: " << "\n";
    }

    /* 2. count -> returns count of keys/values */
    size_t count = points.count(pt2);
    std::cout << "pt2 occurs " << count  << " times" << "\n";

    count = points.count(pt4);
    std::cout << "pt4 occurs " << count  << " times" << "\n";

    /* 3. equal range */
    auto range =  points.equal_range(pt2);
    std::cout << "lower: " << *range.first << " upper: " << *range.second << "\n";
    

    return 0;
}
