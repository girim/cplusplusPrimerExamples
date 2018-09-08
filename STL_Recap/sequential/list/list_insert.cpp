#include <iostream>
#include <list>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    std::list<Point> points;
    Point pt;
    /* 1. single element */
    auto iter  = points.insert(points.begin(), pt);
    printSequentialContainer(points);
    std::cout << "element just inserted is: " << *iter << "\n";

    /* 2. fill */
    points.insert(++points.begin(), 3, pt);
    printSequentialContainer(points);

    /* 3. range */
    std::list<Point> points_0;
    points_0.insert(points_0.begin(), ++points.begin(), points.end());
    printSequentialContainer(points_0);

    /* 4. move */
    points_0.insert(points_0.begin(), std::move(pt));
    printSequentialContainer(points_0);

    /* 5. initializer_list */
    Point center(1, 2);
    points_0.insert(points_0.begin(), {center, center});
    printSequentialContainer(points_0);

    return 0;
}
