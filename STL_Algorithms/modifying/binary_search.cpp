#include <iostream>
#include <vector>
#include <algorithm>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4}, pt5{5};
    std::vector<Point> points = {pt0, pt1, pt2, pt3, pt4};

    std::cout << "Looking for pt4: is found: " << std::boolalpha << std::binary_search(points.begin(), points.end(), pt4) << "\n"; 
    std::cout << "Looking for pt5: is found: " << std::boolalpha << std::binary_search(points.begin(), points.end(), pt5) << "\n"; 
    
    return 0;
}
