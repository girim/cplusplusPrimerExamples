#include <iostream>
#include <algorithm>
#include <deque>
#include <map>
#include "../point.hpp"
#include "../printSeqContainer.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    unsigned numbers[]  = {1, 3, 4, 5};
    unsigned *ptrToNumber;

    ptrToNumber = std::find(std::begin(numbers), std::end(numbers), 4);

    if(ptrToNumber != std::end(numbers))
    {
        std::cout << "Found number: " << *ptrToNumber << "\n";
    }
    else
    {
        std::cout << "Not Found number: "<< "\n";
    }
    
    /* Sequential container */
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::deque<Point> points = {pt1, pt2, pt3, pt2, pt0};

    auto iter = std::find(points.begin(), points.end(), pt2);

    if(iter != points.end()) 
    {
        std::cout << "Found item: " << *iter << "\n";
    }   

    /* Associative container */
    std::map<Point, unsigned> pointsMap;
    pointsMap.insert({{pt0, 1}, {pt1, 2}, {pt2, 2}, {pt3, 3}, {pt1, 3}});

    std::pair<const Point, unsigned> toFind = std::make_pair(pt1, 2);
    auto itr = std::find(pointsMap.begin(), pointsMap.end(), toFind);

    if(itr != pointsMap.end())
    {
        std::cout << "item found: " << itr->first << "\n";
    }

    return 0;
}
