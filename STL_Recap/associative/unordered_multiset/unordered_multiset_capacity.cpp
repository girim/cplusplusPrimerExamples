#include <iostream>
#include <unordered_set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::unordered_multiset<Point, Point> points = {pt0, pt1, pt2, pt2, pt3};
    printAssocContainer(points);

    std::cout << "Size of the container is: " << points.size() << "\n";
    std::cout << "Max size possible : " << points.max_size() << "\n";
    std::cout << "Is empty ? " << (points.empty() ? "true" : "false") << "\n";

    return 0;
}
