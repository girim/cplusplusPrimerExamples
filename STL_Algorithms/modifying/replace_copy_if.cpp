#include <iostream>
#include <algorithm>
#include <deque>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1, 3}, pt2{5, 4}, pt3{9, 3}, pt4{4}, pt5{2, 8};
    std::deque<Point> points = {pt0, pt1, pt2, pt3, pt4};

    printSequentialContainer(points);

    std::replace_copy_if(points.begin(), points.end(), points.begin(), [](const Point& point){
        return (point.getX() == point.getY());
    }, pt5);

    printSequentialContainer(points);
    
    return 0;
}
