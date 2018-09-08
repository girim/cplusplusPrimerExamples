#include <iostream>
#include <unordered_map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1};
    std::unordered_multimap<Point, std::string, Point> points = {{pt0, "x"}, {pt1, "y"}};

    printAssocContainer(points);

    std::cout << "Size of the points: " << points.size() << "\n";
    std::cout << "Maximum size possible: " << points.max_size() << "\n";
    std::cout << "isEmpty ? " << (points.empty() ? "true" : "false") << "\n";
    
    return 0;
}
