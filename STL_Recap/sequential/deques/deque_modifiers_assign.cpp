#include <istream>
#include <deque>
#include "point.hpp"
#include "printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    /* 1. fill */
    std::deque<Point> points;

    Point pt;
    points.assign(2, pt);
    printSequentialContainer(points);

    std::cout << "------range--------" << std::endl;
    /* 2. range */
    std::deque<Point> points_1;
    points_1.assign(points.begin(), points.end());
    printSequentialContainer(points);

    std::cout << "------initializer_list--------" << std::endl;
    /* 3. initializer_list */
    //points_1.assign({pt, pt});
    points_1.assign({pt, pt, pt, pt});

    return 0;
}
