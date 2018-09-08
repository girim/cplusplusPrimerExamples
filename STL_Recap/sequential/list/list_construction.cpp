#include <iostream>
#include <list>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    /* 1. default constructor */
    std::list<Point> points_0;

    Point pt(9, 9);
    /* 2. fill */
    std::list<Point> points_1(2);
    printSequentialContainer(points_1);

    std::list<Point> points_2(2, pt);
    printSequentialContainer(points_2);

    /* 3. range */
    std::list<Point> points_3(++points_2.begin(), points_2.end());
    printSequentialContainer(points_3);

    /* 4. copy constructor */
    std::list<Point> points_4(points_3);
    printSequentialContainer(points_4);

    /* 5. move constructor */
    std::list<Point> points_5(std::move(points_4));
    printSequentialContainer(points_4);
    printSequentialContainer(points_5);

    /* 6. initializer_list */
    std::list<Point> points_6 = {pt, pt};
    printSequentialContainer(points_6);


    return 0;
}
