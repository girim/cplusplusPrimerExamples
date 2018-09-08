#include <iostream>
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
    std::vector<Point> points;

    auto iter = points.emplace(points.begin(), 10, 4);
    printSequentialContainer(points);
    points.emplace(iter, 2, 5);
    printSequentialContainer(points);
    

    return 0;
}
