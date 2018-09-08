#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"

int main(int argc, char const *argv[])
{
    std::vector<unsigned> numbers  = {1, 2, 3, 4, 5, 1, 2, 3, 6};
    unsigned subset[] = {1, 2, 3};

    auto iter  = std::find_end(numbers.begin(), numbers.end(), std::begin(subset), std::end(subset));

    if( iter != numbers.end())
    {
        std::cout << "Subset is found at position: " << (iter - numbers.begin()) << "\n";
    }

    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4}, pt5{5};
    std::vector<Point> points = {pt0, pt1, pt2, pt3, pt4, pt5};
    Point subPoints[] = {pt0, pt1, pt2};

    auto itr  = std::find_end(points.begin(), points.end(), std::begin(subPoints), std::end(subPoints), [](const Point& pt1, const Point& pt2){
            return ((pt1.getX() == (pt2.getX() + 3)) && (pt1.getY() == (pt2.getY() + 3)));
    });
    if(itr != points.end())
    {
        std::cout << "Sub points found at position: " << (itr - points.begin()) << "\n";
    }



    return 0;
}
