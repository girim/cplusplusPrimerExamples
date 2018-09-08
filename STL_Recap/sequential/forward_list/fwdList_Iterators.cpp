#include <iostream>
#include <forward_list>
#include "point.hpp"
#include "printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt1(1, 1), pt2(3, 3), pt3(5, 5), pt4(7, 7);
    std::forward_list<Point> fwdList = {pt1, pt2, pt3, pt4};

    printSequentialContainer(fwdList);

    /* (begin, end) */
    for(std::forward_list<Point>::iterator iter = fwdList.begin(); iter != fwdList.end(); ++iter)
    {
        std::cout << "element is : " << *iter << "\n";
    }

    /* (cbegin, cend) */
    for(std::forward_list<Point>::const_iterator iter = fwdList.cbegin(); iter != fwdList.cend(); ++iter)
    {
        std::cout << "element is : " << *iter << "\n";
    }

    fwdList.insert_after(fwdList.before_begin(), pt4);
    printSequentialContainer(fwdList);

    fwdList.insert_after(fwdList.begin(), pt3);
    printSequentialContainer(fwdList);

    fwdList.insert_after(fwdList.cbefore_begin(), pt2);
    printSequentialContainer(fwdList);




    return 0;
}
