#include <map>
#include <iostream>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt{}, pt1{1, 1};
    std::map<unsigned, Point> points = {{1, pt}, {0, pt1}};

    printAssocContainer(points);
    /* using subscript operator */
    auto val = points[2];
    std::cout << "element with key 2 is: " << val << "\n";
    val = points[3];
    Point pt3{3, 3};
    val = pt3;

    printAssocContainer(points);

    std::cout << "x is : " << points[0].getX() << "\n";
    std::cout << "y is : " << points[0].getY() << "\n";

    /* [] operator returns the reference to the elements in map */
    points[1] = pt1;
    printAssocContainer(points);

    /* using at */
    val = points.at(2);
    std::cout << "val is : " << val << "\n";

    
    try
    {
        val = points.at(4);
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
 
    return 0;
}
