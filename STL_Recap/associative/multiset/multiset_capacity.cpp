#include <iostream>
#include <set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2};
    std::multiset<Point> points = {pt0, pt1, pt2};

    std::cout << "size of container: " << points.size() << "\n";
    std::cout << "is empty: " << (points.empty() ? "true" : "false") << "\n";
    std::cout << "max_size: " << points.max_size() << "\n";

    return 0;
}
