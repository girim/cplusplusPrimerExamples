#include <iostream>
#include <vector>
#include "point.hpp"

int main(int argc, char const *argv[])
{
    /* insert 
        single element - (pos, value)
        fill           - (pos, n, value) 
        range          - (pos, begin, end)
        il             - (pos, {initializer_list})
        move           - (pos, &&value)*/

    std::vector<Point> points;

    Point pt;
    points.insert(points.end(), 5, pt);
    std::cout << "----inserted 5 elements at the end ----" << std::endl;
    points.insert(points.begin(), 1, pt);
    std::cout << "----inserted 1 elements at the begining ----" << std::endl;

    //points.insert(points.begin(), {pt, pt, pt});

    return 0;
}
