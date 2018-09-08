#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4};
    std::vector<Point> points_0 = {pt0, pt1, pt2, pt3};
    std::vector<Point> points_1 = {pt0, pt1, pt2, pt3};
    std::vector<Point> points_2 = {pt1, pt2, pt3, pt4};

    auto result  = std::equal(points_0.begin(), points_0.end(), points_1.begin());
    std::cout << "Is equal: " << std::boolalpha << result << "\n";

    result = std::equal(points_1.begin(), points_1.end(), points_2.begin(), [](const Point& pt1, const Point& pt2){
            return ((pt2.getX() == (pt1.getX() + 1)) && (pt2.getY() == (pt1.getY() + 1)));
    });

    std::cout << "Is equal: " << std::boolalpha << result << "\n";


    return 0;
}
