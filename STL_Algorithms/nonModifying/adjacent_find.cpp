#include <iostream>
#include <algorithm>
#include <list>
#include "../point.hpp"

int main(int argc, char const *argv[])
{
    std::list<int> numbers = {10, 20, 30, 40, 40, 40, 50, 60, 60};
    auto iter  = std::adjacent_find(numbers.begin(), numbers.end());

    if(iter != numbers.end())
    {
        std::cout << "First item to occur twice: " << *iter << "\n";
    }

    iter = std::adjacent_find(iter, numbers.end());

    if(iter != numbers.end())
    {
        std::cout << "Second item to occur twice: " << *iter << "\n";
    }

    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4};
    std::list<Point> points = {pt0, pt1, pt2, pt4, pt3}; //Should find pt2, pt4

    auto itr  =  std::adjacent_find(points.begin(), points.end(), [](const Point& pt1, const Point& pt2){
            return ((pt2.getX() == (pt1.getX() + 2)) && (pt2.getY() == (pt1.getY() + 2)));
    });

    if(itr != points.end())
    {
        std::cout << "Item found is: " << *itr << "\n";
    }


    return 0;
}

