#include <iostream>
#include <list>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt1(1, 2), pt2(4, 5), pt3(8, 7), pt4(2, 5);
    std::list<Point> points = {pt1, pt2, pt3, pt4};

    printSequentialContainer(points);

    /* Bi-directional iterators are used */
    /* (begin, end)) */
    for(std::list<Point>::iterator iter = points.begin(); iter != points.end(); ++iter)
    {
        std::cout << "Element is : " << *iter <<  "\n";
        if(iter->getY() == 5)
        {
            iter->setY(200);
        }
    }

    /* (rbegin, rend) */
    std::cout << "--------------------------------------------" << "\n";
    for(std::list<Point>::reverse_iterator riter = points.rbegin(); riter != points.rend(); ++riter)
    {
        std::cout << "Element is : " << *riter << "\n";
    }

    /* (cbegin, cend) */
    std::cout << "--------------------------------------------" << "\n";
    for(std::list<Point>::const_iterator citer = points.cbegin(); citer != points.cend(); ++citer)
    {
        std::cout << "Element is : " << *citer << "\n";
        if(citer->getY() == 200)
        {
            //citer->setY(5);
        }
    }

    /* (crbegin, crend) */
    std::cout << "--------------------------------------------" << "\n";
    for(std::list<Point>::const_reverse_iterator criter = points.crbegin(); criter != points.crend(); ++criter)
    {
        std::cout << "Element is: " << *criter << "\n";
    }

    return 0;
}
