#include <iostream>
#include <map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt{}, pt1{1, 1}, pt2{2, 2};
    std::map<Point, unsigned> points = {{pt, 1}, {pt1, 2}, {pt2, 3}};
    
    size_t count = points.count(pt1);
    std::cout << "Count is : " << count << "\n";

    count = points.count(pt);
    std::cout << "Count is : " << count << "\n";

    count = points.count(pt2);
    std::cout << "Count is : " << count << "\n";
    
    return 0;
}
