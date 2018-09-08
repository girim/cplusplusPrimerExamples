#include <vector>
#include "point.hpp"

template<typename Container>
void printSequentialContainer(const Container& cont)
{
    std::cout << "[ ";
    auto last = cont.cend()-1;
    for(auto iter = cont.cbegin(); iter != cont.cend(); ++iter)
    {
        (iter == last) ? (std::cout <<  *iter) : (std::cout <<  *iter << ", ");
    }
    std::cout << " ]" << std::endl;
}

int main(int argc, char const *argv[])
{
    /* 1. assign()
            - fill(n, value)
            - range(first, last)
            - initializer_list({}) */

    std::vector<Point> empty;
    std::vector<Point> points(3);
    printSequentialContainer(points);
    std::cout << "capacity of points: " << points.capacity() << std::endl;

    Point point(10, 20);
    points.assign(4, point);   // make 4 to 2 reallocation does not happen
    printSequentialContainer(points);
    std::cout << "capacity of points: " << points.capacity() << std::endl;

    points.assign({point, point});
    printSequentialContainer(points);

    empty.assign(points.begin(), points.end());
    printSequentialContainer(points); 

    /* 2. push_back */
    empty.push_back(point);
    empty.push_back(point);
    printSequentialContainer(empty); 

    /* 3. pop_back */
    empty.pop_back();
    printSequentialContainer(empty); 

    /* 4. insert */
    std::vector<Point> emptyPoints;
    emptyPoints.insert(emptyPoints.begin(), point);
    emptyPoints.insert(emptyPoints.begin(), {point, point});
    printSequentialContainer(emptyPoints);

    return 0;
}
