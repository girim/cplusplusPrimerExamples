#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2, 4}, pt3{5, 6}, pt4{8, 9};
    std::vector<Point> points = {pt0, pt1, pt2, pt3, pt4};

    auto newEnd =  std::remove_if(points.begin(), points.end(), [](const Point& point){
            return (point.getY() == point.getX());
    });

    for(auto iter = points.begin(); iter != newEnd; ++iter)
    {
        std::cout << *iter << "\n";
    }

    return 0;
}
