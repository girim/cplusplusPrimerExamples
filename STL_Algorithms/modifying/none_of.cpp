#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include "../point.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{5, 2}, pt1{1, 2}, pt2{3, 4};
    std::set<Point> points = {pt0, pt1, pt2};

    bool result  = std::none_of(points.begin(), points.end(), [](const Point& point){
            return (point.getX() == point.getY());
    });

    std::cout << "Result: " << std::boolalpha << result << "\n";

    std::map<Point, unsigned> points_0{};
    points_0.emplace(pt0, 1);
    points_0.emplace(pt1, 2);
    points_0.emplace(pt2, 3);

    result  = std::none_of(points_0.begin(), points_0.end(), [](const std::pair<Point, unsigned>& point){
            return (point.first.getX() == point.first.getY());
    });
    std::cout << "Result: " << std::boolalpha << result << "\n";

    return 0;
}
