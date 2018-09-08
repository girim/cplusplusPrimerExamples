#include <iostream>
#include <unordered_map>
#include <utility>
#include <functional>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::unordered_map<Point, unsigned, Point> points;

    /* 1. insert a single value using copy*/
    auto iter  = points.insert({pt0, 10});
    std::cout << "inserted element key: " << iter.first->first << " Value: "<< iter.first->second << "\n";

    points.insert({pt1, 20});
    points.insert({pt2, 30});

    printAssocContainer(points);

    iter = points.insert({pt1, 50});
    std::cout << "inserted element key: " << iter.first->first << " Value: "<< iter.first->second << "\n";

    /* 2. insert a single value using move */
    unsigned temp = 100;
    iter = points.insert(std::pair<Point, unsigned>(pt3, 100));
    std::cout << iter.second << "\n";

    /* 3. insert a single value using hint*/
    Point pt5{5};
    points.insert(points.begin(), {pt5, 90});
    printAssocContainer(points);

    /* 4. using range */
    std::unordered_map<Point, unsigned, Point> points_0;
    points_0.insert(points.begin(), points.end());
    printAssocContainer(points_0);

    /* 5. using initializer_list */
    std::unordered_map<Point, unsigned, Point> points_1({{pt0, 1}, {pt1, 2}});
    printAssocContainer(points_1);

    return 0;
}
