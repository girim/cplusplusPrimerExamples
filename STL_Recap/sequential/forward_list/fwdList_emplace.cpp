#include <iostream>
#include <forward_list>
#include "point.hpp"
#include "printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    /* emplace_front */
    std::forward_list<Point> points;
    points.emplace_front(7, 8);
    points.emplace_front(1, 5);
    points.emplace_front(2, 4);

    printSequentialContainer(points);

    points.emplace_after(points.before_begin(), 3, 3);
    printSequentialContainer(points);

    /* Emplace element at before front */
    points.emplace_after(points.before_begin(), 2, 2);
    printSequentialContainer(points);

    /* Emplace element at the front */
    points.emplace_after(points.begin(), 1, 1);
    printSequentialContainer(points);

    /* Emplace element at the midle */
    points.emplace_after(std::next(points.begin(), 2), 0, 0);
    printSequentialContainer(points);

    /* Emplace element at the end - first find the size and remove 1 from it */
    auto size = std::distance(points.begin(), points.end());
    points.emplace_after(std::next(points.begin(), size-1), 0, 0);
    printSequentialContainer(points);

    return 0;
}
