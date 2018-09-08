#include <iostream>
#include <set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::multiset<Point> points;

    /* 1. insert single element */
    auto iter  = points.insert(pt2);
    std::cout << "Inserted element is : " << *iter << "\n";

    printAssocContainer(points);
    
    /* 2. insert single element with position */
    iter = points.insert(std::next(points.begin()), pt3);
    printAssocContainer(points);

    /* 3. insert elements with Range */
    std::multiset<Point> points_0;
    points_0.insert(points.begin(), points.end());
    printAssocContainer(points_0);

    /* 4. insert elements with initializer_list */
    points.insert({pt0, pt1, pt3});
    printAssocContainer(points);

    return 0;
}
