#include <iostream>
#include <map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    std::map<Point, unsigned> points;
    Point pt{}, pt1{1, 1}, pt2{2, 2}, pt3{3, 3};

    /* 1. single element insertion -- return type std::pair<iterator, bool> */
    auto res = points.insert({pt3, 1});
    std::cout << "res.first->first : " << res.first->first << "\n";
    std::cout << "res.first->second : " << res.first->second<< "\n";
    std::cout << "res.second : " << res.second << "\n";
    points.insert({pt, 2});
    points.insert({pt2, 3});
    points.insert({pt1, 4});

    printAssocContainer(points);
    /* if key already exists, then value won't be inserted */
    res = points.insert({pt, 5});
    std::cout << "res: key -> " << res.first->first << " val-> " << res.first->second << "\n";
    std::cout << "res: does it inserted ? " << (res.second ? "true": "false") << "\n";
    printAssocContainer(points);

    /* 2. range */
    std::map<Point, unsigned> points_0(points.begin(), points.end());
    printAssocContainer(points_0);

    std::map<Point, unsigned> points_1(std::next(points_0.begin(), 1), std::prev(points_0.end()));
    printAssocContainer(points_1);

    /* 3. initializer_list */
    std::map<Point, unsigned> points_2 = {{pt3, 1}, {pt2, 2}, {pt1, 3},{pt, 0}};
    printAssocContainer(points_2);

    /* 4. with hint */
    auto iter = points_2.end();
    Point pt4{4, 4};
    points_2.insert(iter, {pt4, 4});
    printAssocContainer(points_2);

    return 0;
}
