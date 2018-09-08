#include <iostream>
#include <list>
#include "../point.hpp"
#include "../printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    /* front --returns reference  the first  */
    std::list<Point> points;
    points.emplace_back(2, 4);
    points.emplace_back(2, 3);
    printSequentialContainer(points);

    if ( points.front().getY() == 4 )
    {
        points.front().setY(8);        
    }
    printSequentialContainer(points);

    points.back().setY(10);
    printSequentialContainer(points);

    return 0;
}
