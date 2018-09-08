#include <set>
#include <iostream>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::multiset<Point> points = {pt0, pt1, pt3, pt2};

    printAssocContainer(points);

    /* [begin, end) */
    for(std::multiset<Point>::iterator iter = points.begin(); iter != points.end(); ++iter)
    {
        std::cout << "Key/Value is: " << *iter << "\n";
        if(iter->getX() == 0)
        {
            //*iter =  pt2;  // cannot change the key/value as it is constant
        }
    }
    std::cout << "\n";

    /* [cbegin, cend) */
    for(std::multiset<Point>::const_iterator iter = points.cbegin(); iter != points.cend(); ++iter)
    {
        std::cout << "Key/Value is: " << *iter << "\n";
    }
    std::cout << "\n";

    /* [rbegin, rend) */
    for(std::multiset<Point>::reverse_iterator iter = points.rbegin(); iter != points.rend(); ++iter)
    {
        std::cout << "Key/Value is: " << *iter << "\n";
    }
    std::cout << "\n";

    /* [crbegin, crend) */
    for(std::multiset<Point>::const_reverse_iterator iter = points.crbegin(); iter != points.crend(); ++iter)
    {
        std::cout << "Key/Value is: " << *iter << "\n";
    }
    std::cout << "\n";

    return 0;
}
