#include <iostream>
#include <unordered_set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::unordered_set<Point, Point> points;

    /* 1. single element insertion */
    auto result =  points.insert(pt3);
    std::cout << "inserted item: " << *result.first << " is successful? " << result.second << "\n";

    /* 2. initializer_list */
    points.insert({pt2, pt1, pt0});
    printAssocContainer(points);

    /* 3. Range */
    std::unordered_set<Point, Point> points_0;
    points_0.insert(points.begin(), points.end());
    printAssocContainer(points_0);

    /* 4. insert with hint */
    Point pt4{4};
    points_0.insert(points_0.begin(), pt4);
    printAssocContainer(points_0);

    return 0;
}
