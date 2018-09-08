#include <iostream>
#include <forward_list>
#include "point.hpp"
#include "printSeqContainer.hpp"


int main(int argc, char const *argv[])
{
    std::forward_list<Point> fwdList_0;

    /* 1. fill */
    std::forward_list<Point> fwdList_1(4);
    printSequentialContainer(fwdList_1);

    Point pt{4, 5};
    std::forward_list<Point> fwdList_2(2, pt);
    printSequentialContainer(fwdList_2);

    /* 2. range */
    std::forward_list<Point> fwdList_3(std::next(fwdList_1.begin(), 2), fwdList_1.end());
    printSequentialContainer(fwdList_3);

    /* 3. copy */
    std::forward_list<Point> fwdList_4(fwdList_3);
    printSequentialContainer(fwdList_4);

    /* 4. move */
    std::forward_list<Point> fwdList_5(std::move(fwdList_4));
    printSequentialContainer(fwdList_5);
    printSequentialContainer(fwdList_4);

    /* 5. initializer_list */
    std::forward_list<Point> fwdList_6 = {pt, pt};
    printSequentialContainer(fwdList_6);

    return 0;
}

