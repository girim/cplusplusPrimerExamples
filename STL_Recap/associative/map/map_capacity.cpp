#include <iostream>
#include <map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point  pt{}, pt1{1, 1}, pt2{2, 2};
    std::map<Point, unsigned> points = {{pt, 1}, {pt1, 2}, {pt2, 3}};
    std::cout << "size of points is : " << points.size() << "\n";

    std::cout << "is container empty? " << (points.empty() ? "ture" : "false") << "\n";
    
    return 0;
}
