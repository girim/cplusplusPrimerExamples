#include <iostream>
#include <set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::set<Point> points;

    /* 1. single element insertion */
    auto result = points.insert(pt0);
    std::cout << "Inserted element key/value : "<< *result.first << " is successful: " << (result.second ? "true" : "false") << "\n";
    points.insert(pt1);

    printAssocContainer(points);
    result = points.insert(pt1);
    std::cout << "Inserted element key/value : "<< *result.first << " is successful: " << (result.second ? "true" : "false") << "\n";

    /* 2. single element with hint */
    auto iter  = points.insert(std::prev(points.end()), pt2);
    std::cout << "Inserted element key/value: " << *iter << "\n";
    printAssocContainer(points);

    /* 3. range of elements */
    std::set<Point> points_0;
    points_0.insert(points.begin(), points.end());
    printAssocContainer(points_0);

    /* 4. initializer_list */
    std::set<Point> points_1;
    points_1.insert({pt3, pt0, pt1, pt2});
    printAssocContainer(points_1);

    return 0;
}
