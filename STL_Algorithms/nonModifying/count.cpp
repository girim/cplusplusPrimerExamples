#include <iostream>
#include <algorithm>
#include <deque>
#include <map>
#include "../point.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4};
    std::deque<Point> points = {pt0, pt1, pt1, pt3, pt2, pt1};
    
    auto count = std::count(points.begin(), points.end(), pt1);
    std::cout << "Item pt1 present " << count << " times: " << "\n";

    count = std::count(points.begin(), points.end(), pt4);
    std::cout << "Item pt4 present " << count << " times: " << "\n";

    std::multimap<Point, std::string> pointMap;
    pointMap.insert({{pt0, "India"}, {pt0, "Austria"}, {pt0, "India"}, {pt1, "Germany"}});

    std::pair<const Point, std::string> toFind = std::make_pair(pt0, "India");
    count = std::count(pointMap.begin(), pointMap.end(), toFind);
    std::cout << "Item present " << count << " times: " << "\n";

    return 0;
}
