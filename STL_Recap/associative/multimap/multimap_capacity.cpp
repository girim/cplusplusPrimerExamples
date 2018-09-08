#include <iostream>
#include <map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{0, 0}, pt1{1, 1}, pt2{2, 2};
    std::multimap<Point, unsigned> points = {{pt0, 1}, {pt1, 1}, {pt2, 2}};

    /* size - no of elements in multimap */
    std::cout << "Number of points: " << points.size() << "\n";

    /* max_size  max number of elements that can be constructed*/
    std::cout << "Max number of elements that can be constructed: " << points.max_size() <<  "\n";

    /* empty */
    std::cout << "Is empty: " << (points.empty() ? "true" : "false") << "\n";
          
    return 0;
}
