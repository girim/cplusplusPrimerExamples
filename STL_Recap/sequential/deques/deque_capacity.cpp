#include <iostream>
#include <deque>
#include "point.hpp"
#include "printSeqContainer.hpp"

int main(int argc, char const *argv[])
{
    /* size - returns no of elements in unsigned integral*/
    std::deque<Point> points(4);
    printSequentialContainer(points);
    std::cout << "size of the points: " << points.size() << "\n";

    /* resize(n, value),  n < size
                          n > size */

    points.resize(2);
    std::cout << "size of the points: " << points.size() << "\n";
    printSequentialContainer(points);
    
    points.resize(3);
    printSequentialContainer(points);
    std::cout << "size of the points: " << points.size() << "\n";

    Point pt(11,22);
    points.resize(5, pt);
    std::cout << "size of the points: " << points.size() << "\n";
    printSequentialContainer(points);

    /* empty */
    std::cout << "is empty? " << ( points.empty() ? "true" : "flase") << "\n";

    /* shrink_to_fit */
    
    return 0;
}
