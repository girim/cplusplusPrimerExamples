#include <set>
#include <iostream>
#include <functional>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

bool comparatorFunction(const Point& pt1, const Point& pt2)
{
    return (pt1 > pt2);
}

class comparatorClass
{
    public:
    bool operator()(const Point& pt1, const Point& pt2)
    {
        return (pt1.getX() > pt2.getX());
    }
};

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt4{4};
    /* using function pointer */
    std::set<Point, bool(*)(const Point&, const Point&)> points(comparatorFunction);
    points.emplace(pt0);
    points.emplace(pt1);
    points.emplace(pt2);
    points.emplace(pt4);

    printAssocContainer(points);

    Point pt5{3, 1}, pt6{1, 6}, pt7{7, 9};
    /* using function object */
    std::set<Point, comparatorClass> points_0 = {pt6, pt5, pt7};
    printAssocContainer(points_0);

    /* using lambda */
    Point pt8{1, 4}, pt9{8, 6}, pt10{8, 0};
    std::set<Point, std::function<bool(const Point&, const Point&)>> points_1([](const Point& pt1, const Point& pt2){
        return (pt1.getY() > pt2.getY());
    });
    points_1.emplace(pt10);
    points_1.emplace(pt8);
    points_1.emplace(pt9);
    printAssocContainer(points_1);

    return 0;
}
