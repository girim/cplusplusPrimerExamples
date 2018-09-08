#include <iostream>
#include <algorithm>
#include <list>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{3, 4}, pt3{3};
    std::list<Point> points = {pt0, pt1, pt2, pt3};

    auto iter =  std::find_if_not(points.begin(), points.end(), [](const Point& point){
            return (point.getX() == point.getY());
    });

    if(iter != points.end())
    {
        std::cout << "Found item: " << *iter << "\n";
    }

    return 0;
}
