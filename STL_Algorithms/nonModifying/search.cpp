#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::vector<Point> points{pt0, pt1, pt2, pt3, pt2, pt1};
    Point toSearch[] = {pt2, pt3, pt2};

    auto iter  = std::search(points.begin(), points.end(), std::begin(toSearch), std::end(toSearch));

    if(iter != points.end())
    {
        std::cout << "Found sequence starts from : "  << *iter << "\n";
    }

    std::vector<Point> points_0{pt0, pt1, pt2, pt3, pt0};
    Point toSrc[] = {pt0, pt1, pt2};

    auto itr =  std::search(points_0.begin(), points_0.end(), std::begin(toSrc), std::end(toSrc), [](const Point& pt1, const Point& pt2){
            return ((pt1.getX() == (pt2.getX() + 1)) && (pt1.getY() == (pt2.getY() + 1)));
    });
    if(itr != points_0.end())
    {
        std::cout << "Found sequence starts from: " << *itr << "\n";
    }

    return 0;
}
