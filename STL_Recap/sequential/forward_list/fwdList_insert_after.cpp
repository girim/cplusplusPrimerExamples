#include <iostream>
#include <forward_list>
#include "point.hpp"
#include "printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    std::forward_list<Point> points;
    /* 1. single element */
    Point pt;

    /* insert_after returns the iterator to the last inserted element */
    auto iter  = points.insert_after(points.before_begin(), pt);
    printSequentialContainer(points);
    std::cout << "iter points to last inserted element: " << *iter << "\n";

    points.insert_after(points.begin(), pt);
    printSequentialContainer(points);

    /* 2. fill */
    Point pt1(1, 1);
    iter  = points.insert_after(points.begin(), 2, pt1);
    std::cout << "iter points to last inserted element: " << *iter << "\n";
    printSequentialContainer(points);

    /* 3. range */
    std::forward_list<Point> points_1;
    points_1.insert_after(points_1.before_begin(), points.begin(), points.end());
    printSequentialContainer(points);

    /* 4. initailizer_list */
    std::forward_list<Point> points_2;
    points_2.insert_after(points_2.before_begin(), {pt1, pt, pt1, pt});
    printSequentialContainer(points_2);

    return 0;
}
