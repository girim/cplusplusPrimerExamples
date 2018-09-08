#include <iostream>
#include <set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    /* size -- returns no of elements in set */
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::set<Point> points = {pt0, pt1, pt2, pt3};

    std::cout << "size of set points is : " << points.size() << "\n";

    /* empty */
    std::cout << "is set empty: " << (points.empty() ? "true" : "false") << "\n";

    /* max_size */
    std::cout << "max_size: " << points.max_size() << "\n";
    
    return 0;
}
