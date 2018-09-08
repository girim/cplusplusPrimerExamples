#include <iostream>
#include <forward_list>
#include "point.hpp"
#include "printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    /* fill */
    std::forward_list<Point> fwdList;
    Point pt1(1, 3);
    fwdList.assign(4, pt1);
    printSequentialContainer(fwdList);

    /* range */
    std::forward_list<Point> fwdList_0;
    fwdList_0.assign(std::next(fwdList.cbegin(), 2), fwdList.cend());
    printSequentialContainer(fwdList_0);

    /* initializer_list */
    std::forward_list<Point> fwdList_1;
    fwdList_1.assign({pt1, pt1, pt1});
    printSequentialContainer(fwdList_1);

    return 0;
}
