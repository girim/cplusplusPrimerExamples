#include <map>
#include <iostream>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    std::map<unsigned, Point> points;
    Point pt, pt1{1, 1}, pt2{2, 2};
    auto res =  points.emplace(1, pt);
    std::cout <<"res: first->key " << res.first->first << "\n"; 
    std::cout <<"res: first->Value " << res.first->second << "\n"; 
    std::cout <<"is insertion successful: " << res.second << "\n";

    printAssocContainer(points);

    points.emplace(3, pt1);
    points.emplace(2, pt2);

    printAssocContainer(points);
    res = points.emplace(2, pt);
    std::cout << "key: " << res.first->first << " Value: " << res.first->second << "\n";
    std::cout << "result of insertion: " << res.second << "\n";

    Point pt4{4, 4};
    auto result = points.emplace_hint(points.begin(), 4, pt4);
    printAssocContainer(points);

    return 0;
}
