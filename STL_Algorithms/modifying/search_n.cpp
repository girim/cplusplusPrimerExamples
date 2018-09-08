#include <iostream>
#include <algorithm>
#include <deque>
#include "../point.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::deque<Point> points = {pt1, pt0, pt0, pt2, pt3, pt3};

    auto iter = std::search_n(points.begin(), points.end(), 2, pt0);

    if(iter != points.end())
    {
        std::cout << "item found at position " << (iter - points.begin()) << "\n";
    }

    /* with predicate */
    iter  = std::search_n(points.begin(), points.end(), 2, pt0, [](const Point& pt1, const Point& pt2){
            return ((pt2.getX() == (pt1.getX() + 2)) && (pt2.getY() == (pt1.getY() + 2)));
    });

    if( iter != points.end())
    {
        std::cout << "item found at position " << (iter - points.begin()) << "\n";
    }

    return 0;
}
