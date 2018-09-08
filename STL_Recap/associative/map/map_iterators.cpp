#include <iostream>
#include <map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt{}, pt1{1, 1}, pt2{2, 2}, pt3{3, 3};
    std::map<Point, unsigned> points = {{pt3, 0}, {pt2, 1}, {pt, 2}, {pt1, 3}};

    //printAssocContainer(points);

    /* [begin, end) */
    for(std::map<Point, unsigned>::iterator iter =  points.begin();  iter!= points.end(); ++iter)
    {
        std::cout << "Key: " << iter->first << " Value: " << iter->second << "\n";
        if(iter->first.getX() == 0)
        {
            //iter->first = pt1;
            iter->second = 99;
        }
    }
    //printAssocContainer(points);

    /* [cbegin, cend) */
    for(std::map<Point, unsigned>::const_iterator iter = points.cbegin(); iter != points.cend(); ++iter)
    {
        std::cout << "Key: " << iter->first << " Value: " << iter->second << "\n";
        if(iter->first.getX() == 0)
        {
            //iter->first = pt1;
            //iter->second = 0;
        }
    }

    /* [rbegin, rend) */
    for(std::map<Point, unsigned>::reverse_iterator iter = points.rbegin(); iter != points.rend(); ++iter)
    {
        std::cout << "Key: " << iter->first << " Value: " << iter->second << "\n";
        if(iter->first.getX() == 0)
        {
            iter->second = 0;
        }
    }

    /* [crbegin, crend) */
    for(std::map<Point, unsigned>::const_reverse_iterator iter = points.crbegin(); iter != points.crend(); ++iter)
    {
        std::cout << "Key: " << iter->first << " Value: " << iter->second << "\n";
    }

    return 0;
}


