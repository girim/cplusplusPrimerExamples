#include <iostream>
#include <algorithm>
#include <list>
#include "../point.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::list<Point> list1 = {pt0, pt1, pt2, pt3};
    std::list<Point> list2 = {pt0, pt1, pt2, pt3};
    std::list<Point> list3 = {pt0, pt1, pt3, pt2};

    auto result  = std::mismatch(list1.begin(), list1.end(), list2.begin());
    if(result.first == list1.end() && result.second == list2.end())
    {
        std::cout << "Both sequences match: " << "\n";
    }

    result = std::mismatch(list1.begin(), list1.end(), list3.begin());
    if(result.first != list1.end() || result.second != list3.end())
    {
        std::cout << "Mismatch found at list1: " << *result.first << "\n";
        std::cout << "Mismatch found at list3: " << *result.second << "\n";
    }

    return 0;
}
