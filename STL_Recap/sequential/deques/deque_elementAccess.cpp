#include <istream>
#include <deque>
#include "point.hpp"
#include "printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    /* 1. operator [] */
    std::deque<Point> points(4);
    printSequentialContainer(points);

    points[0].setX(4); // returns ref to element
    points[0].setY(3);

    printSequentialContainer(points);

    /* 2. at  --> thorws out_of_range exception*/
    
    try
    {
        points.at(5);
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }

    /* 3. front */
    points.front().setX(9);
    points.front().setY(8);

    printSequentialContainer(points);

    /* 4. back */
    points.back().setX(2);
    points.back().setY(3);
    printSequentialContainer(points);
    

    return 0;
}
