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
            return (pt1.getY() > pt2.getX());
        }
};

int main(int argc, char const *argv[])
{
    /* 1. using function pointers */
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::multiset<Point, bool(*)(const Point&, const Point&)> points(comparatorFunction);
    points.insert({pt0, pt1, pt3, pt2, pt3});

    printAssocContainer(points);

    /* 2. using function object */
    std::multiset<Point, comparatorClass> points_0 = {pt0, pt1, pt3, pt2};
    printAssocContainer(points_0);

    /* 3. using lambda functions */
    std::multiset<Point, std::function<bool(const Point&, const Point&)>> points_1([](const Point& pt1, const Point& pt2){
        return (pt1.getX() > pt2.getX());
    });
    points_1.insert({pt0, pt1, pt3, pt2, pt3});
    printAssocContainer(points_1);

    return 0;
}
