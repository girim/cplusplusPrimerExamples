#include <iostream>
#include <set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4};
    std::set<Point>  points = {pt0, pt2, pt1, pt3};

    std::set<Point>::iterator iter = points.find(pt2);

    if(iter != points.end())
    {
        std::cout << "Item " << *iter << " found in the set " << "\n";
    }

    iter = points.find(pt4);
    if(iter == points.end())
    {
        std::cout << "item not found in the list: " << "\n";
    }

    return 0;
}
