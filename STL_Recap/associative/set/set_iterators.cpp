#include <set>
#include <iostream>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4};
    std::set<Point> points = {pt1, pt0, pt3, pt2};
    printAssocContainer(points);

    /* [begin, end) */
    for(std::set<Point>::iterator iter = points.begin(); iter != points.end(); ++iter)
    {
        std::cout << "key/value is: " << *iter << "\n";
        if((iter->getX() == 0) && (iter->getY() == 0))
        {
            //iter->setX(10);
        }
    }
    std::cout << "\n";

    /* [cbegin, cend) */
    for(std::set<Point>::const_iterator iter = points.cbegin(); iter != points.cend(); ++iter)
    {
        std::cout << "key/value is: " << *iter << "\n";
    }
    std::cout << "\n";

    /* [rbegin, rend) */
    for(std::set<Point>::reverse_iterator iter = points.rbegin(); iter != points.rend(); ++iter)
    {
        std::cout << "key/value is: " << *iter << "\n";
    }
    std::cout << "\n";

    /* [crbegin, crend) */
    for(std::set<Point>::const_reverse_iterator iter = points.crbegin(); iter != points.crend(); ++iter)
    {
        std::cout << "key/value is: " << *iter << "\n";
    }

    return 0;
}
