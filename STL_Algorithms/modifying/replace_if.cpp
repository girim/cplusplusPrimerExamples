#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1, 4}, pt2{3, 4}, pt3{9, 8}, pt99{99};
    std::vector<Point> points = {pt0, pt1, pt2, pt3};

    printSequentialContainer(points);
    
    std::replace_if(points.begin(), points.end(), [](const Point& point){
        return (point.getX() != point.getY());
    }, pt99);
    printSequentialContainer(points);


    return 0;
}
