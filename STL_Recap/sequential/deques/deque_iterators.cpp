#include <iostream>
#include <deque>
#include "point.hpp"
#include "printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt1(1, 2), pt2(3, 4), pt3(5, 6);
    Point center;
    std::deque<Point> points = {pt1, pt2, pt3};
    printSequentialContainer(points);

    /* [begin, end) */
    for(std::deque<Point>::iterator iter = points.begin(); iter != points.end(); ++iter)
    {
        std::cout << "[begin, end) element is : " << *iter << "\n";

        if(iter->getX() == 3)
        {
            *iter = center;
        }
    }

    /* [cbegin, cend) */
    for(std::deque<Point>::const_iterator citer = points.cbegin(); citer != points.cend(); ++citer)
    {
        std::cout << "[cbegin, cend) element is: " << *citer << "\n";
        //*citer = pt; 
    }

    /* [rbegin, rend) */
    for(std::deque<Point>::reverse_iterator riter = points.rbegin(); riter != points.rend(); ++riter)
    {
        std::cout << "[rbegin, rend) element is: " << *riter << "\n";
        if(riter->getX() == 0)
        {
            *riter = pt2;
        }
    }

    /* [crbegin, crend] */
    for(std::deque<Point>::const_reverse_iterator criter = points.crbegin(); criter != points.crend(); ++criter)
    {
        std::cout << "[crbegin, crend) element is: " << *criter << "\n";
        //*criter = center
    }

    return 0;
}
