#include <map>
#include <iostream>
#include <functional>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

struct comparatorOne
{
    bool operator()(const Point& pt1, const Point& pt2)
    {
        return (pt1 > pt2);
    }
};

bool comparatorTwo(const Point& pt1, const Point& pt2)
{
    return (pt1.getX() > pt2.getX());
}

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1, 1}, pt2{2, 2}, pt3{3, 3}, pt4{4, 4};
    /* Using 'Functor's' as comparators */
    std::multimap<Point, unsigned, comparatorOne>  points = {{pt0, 1}, {pt1, 2}, {pt2, 3}, {pt3, 4}, {pt4, 5}};

    printAssocContainer(points);


    Point pt5{5, 1}, pt6{4, 2}, pt7{1, 3};
    /* Using 'function pointers' as comparators */
    std::multimap<Point, unsigned, bool(*)(const Point&, const Point&)> points_0(comparatorTwo);
    points_0.emplace(pt7, 1);
    points_0.emplace(pt6, 2);
    points_0.emplace(pt5, 3);
    points_0.emplace(pt6, 4);

    printAssocContainer(points_0);

    std::multimap<Point, unsigned, std::function<bool(const Point&, const Point&)>>  points_1([](const Point& pt1, const Point& pt2){
        return pt1 > pt2;
    });

    points_1.emplace(pt0, 1);
    points_1.emplace(pt3, 2);
    points_1.emplace(pt2, 3);
    points_1.emplace(pt0, 4);
    points_1.emplace(pt4, 5);
    printAssocContainer(points_1);

    /* Using built in function objects */
    std::multimap<Point, unsigned, std::greater<Point>> points_2 = {{pt0, 1}, {pt1, 2}, {pt2, 3}, {pt3, 4}, {pt4, 5}};
    printAssocContainer(points_2);


    return 0;
}
