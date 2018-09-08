#include <iostream>
#include <deque>
#include "printSeqContainer.hpp"
#include "point.hpp"

int main(int argc, char const *argv[])
{
    /* Deque construction */
    /* 1. default */
    std::deque<int> numbers_0;

    /* 2. fill */
    std::deque<float> numbers_1(3, 1.2);
    printSequentialContainer(numbers_1);

    Point center(2, 2);
    std::deque<Point> points_0(2);
    printSequentialContainer(points_0);

    std::deque<Point> points_1(2, center);
    printSequentialContainer(points_1);

    /* 3. range */
    std::deque<Point> points_2(points_0.begin(), points_0.end());
    printSequentialContainer(points_2);

    /* 4. copy constructor */
    std::deque<Point> points_3(points_2);
    printSequentialContainer(points_3);

    /* 5. move constructor */
    std::deque<Point> points_4(std::move(points_3));
    printSequentialContainer(points_4);
    printSequentialContainer(points_3);

    std::cout << "------------------------------" << std::endl;
    /* 6. initializer_list */
    std::deque<Point> points_5 = {center, center};
    printSequentialContainer(points_5);

    return 0;
}
 