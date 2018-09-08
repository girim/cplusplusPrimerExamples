#include <iostream>
#include <map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1, 1}, pt2{2, 2}, pt3{3, 3};
    std::map<unsigned, Point> points = {{1, pt3}, {2, pt2}, {3, pt1}, {4, pt0}};

    printAssocContainer(points);

    /* cannot modify 'keys' of Map as Keys are always constant*/
    /* iterators [begin, end) */
    for(std::multimap<unsigned, Point>::iterator iter = points.begin(); iter != points.end(); ++iter)
    {
        std::cout << "key: " << iter->first << " value: " << iter->second << "\n";
        if(iter->second.getX() == 0)
        {
            iter->second = pt1;
        }
    }
    printAssocContainer(points);

    /* const_iterators [cbegin, cend)  */
    for(std::multimap<unsigned, Point>::const_iterator iter = points.cbegin(); iter != points.cend(); ++iter)
    {
        std::cout << "key: " << iter->first << " value: " << iter->second << "\n";
        if(iter->second.getX() == 1)
        {
            //iter->second = pt0;
        }
    }

    /* reverse_iterator [rbegin, rend)*/
    for(std::multimap<unsigned, Point>::reverse_iterator iter =  points.rbegin(); iter != points.rend(); ++iter)
    {
        std::cout << "key: " << iter->first << " value: " << iter->second << "\n";
        if(iter->second.getX() ==  1)
        {
            iter->second = pt0;
        }
    }
    printAssocContainer(points);

    /* const_reverse_iterator [crbegin, crend)*/
    for(std::multimap<unsigned, Point>::const_reverse_iterator iter = points.crbegin(); iter != points.crend(); ++iter)
    {
        std::cout << "key: " << iter->first << "value: " << iter->second << "\n";
        /* can not change both Key and Value */
    }

    

    return 0;
}
