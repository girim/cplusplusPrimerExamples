#include <unordered_set>
#include <iostream>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::unordered_multiset<Point, Point> points = {pt0, pt1, pt2, pt3, pt2};

    /* Uses forward iterator */
    for(std::unordered_multiset<Point, Point>::iterator iter = points.begin(); iter != points.end(); ++iter)
    {
        std::cout << "key/value: " << *iter << "\n";
    }
    std::cout << "\n";

    for(std::unordered_multiset<Point, Point>::const_iterator iter = points.cbegin(); iter != points.cend(); ++iter)
    {
        std::cout << "key/value: " << *iter << "\n";
    }

    return 0;
}
