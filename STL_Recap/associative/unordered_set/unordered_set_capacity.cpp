#include <iostream>
#include <unordered_set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2};
    std::unordered_set<Point, Point> points = {pt0, pt1, pt2};

    printAssocContainer(points);

    std::cout << "Size of the set is : " << points.size() << "\n";
    std::cout << "is empty ? " << (points.empty() ? "true" : "false") << "\n";
    std::cout << "max_size: " << points.max_size() << "\n";
    
    return 0;
}
