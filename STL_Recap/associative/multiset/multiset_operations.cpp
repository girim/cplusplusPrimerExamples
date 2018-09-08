#include <iostream>
#include <set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4};
    std::multiset<Point> points = {pt0, pt1, pt2, pt2, pt3};
    printAssocContainer(points);

    /* 1. find */
    auto iter = points.find(pt2);

    if(iter != points.end()){
        std::cout << "Found element: " << *iter << "\n";
    }

    iter = points.find(pt4);
    if(iter == points.end()){
        std::cout << "element not found " << "\n";
    }

    /* 2. count --> returns no of elements with same key */
    size_t count = points.count(pt2);
    std::cout << "No of keys are : " << count << "\n";

    /* 3. bound */
    auto lowerBound = points.lower_bound(pt2);
    auto upperBound = points.upper_bound(pt2);
    auto result = points.equal_range(pt2);

    std::cout << "lower_bound: " << *lowerBound << "\n";
    std::cout << "upper_bound: " << *upperBound << "\n";
    std::cout << "result-> lower: " << *result.first << "\n";
    std::cout << "result-> upper: " << *result.second << "\n";

    return 0;
}
