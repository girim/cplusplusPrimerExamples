#include <iostream>
#include <unordered_set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4};
    std::unordered_multiset<Point, Point> points = {pt0, pt1, pt2, pt1, pt2, pt1, pt3};

    printAssocContainer(points);

    /* 1.find */
    auto iter = points.find(pt1);
    
    if(iter != points.end())
    {
        std::cout << "Item found: " << *iter << "\n";
    }

    iter = points.find(pt4);
    if(iter == points.end()){
        std::cout << "Item not found: " << "\n";
    }

    /* 2.count */
    std::size_t noOfkeys =  points.count(pt1);
    std::cout << "no of entries of pt1: " << noOfkeys << "\n";

    noOfkeys = points.count(pt4);
    std::cout << "no of entries of pt1: " << noOfkeys << "\n";

    /*3. equal_range  */
    auto result = points.equal_range(pt1);
    std::cout << "lower: " << *result.first << "\n";
    std::cout << "upper: " << *result.second << "\n";

    for(auto iter = result.first; iter != result.second; ++iter)
    {
        std::cout << "item : " << *iter << "\n";
    }

    return 0;
}
