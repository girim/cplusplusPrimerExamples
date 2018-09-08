#include <algorithm>
#include <iostream>
#include "../point.hpp"
#include <vector>

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1, 5}, pt2{2}, pt3{3, 5};
    std::vector<Point> points = {pt0, pt1, pt2, pt3};

    /* count all the points with x != y */
    auto count =  std::count_if(points.begin(), points.end(), [](const Point& point){
            return (point.getX() != point.getY());
    });

    std::cout << "No of points with unequal x& y's are: " << count << "\n";

    return 0;
}
