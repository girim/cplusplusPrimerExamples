#include <map>
#include <iostream>
#include <functional>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

/* functor */
struct comparatorOne
{
    bool operator()(const Point& pt1, const Point& pt2)
    {
        return pt1 > pt2;
    }
};

/* function */
bool comparatorTwo(const Point& pt1, const Point& pt2)
{
    return pt1 > pt2;
}

int main(int argc, char const *argv[])
{
    /* 1. Using 'functor' as comparator */
    std::map<Point, unsigned, comparatorOne> points_1;
    Point pt{}, pt1{1, 1}, pt2{2, 2}, pt3{3, 3};
    points_1.insert({pt, 0});
    points_1.insert({pt1, 1});
    points_1.insert({pt2, 2});
    points_1.insert({pt3, 3});

    printAssocContainer(points_1);

    /* 2. Using 'function pointer' as comparator */
    bool(*fp)(const Point&, const Point&) = comparatorTwo;
    std::map<Point, unsigned, bool(*)(const Point&, const Point&)> points_2(fp);
    points_2.insert({pt, 0});
    points_2.insert({pt1, 1});
    points_2.insert({pt2, 2});
    points_2.insert({pt3, 3});

    printAssocContainer(points_2);

    /* 3. Using 'lambda' as comparator */
    std::map<Point, unsigned, std::function<bool(const Point&, const Point&)>> points_3([](const Point& pt1, const Point& pt2){
        return pt1 > pt2;
    });
    points_3.insert({pt, 0});
    points_3.insert({pt1, 1});
    points_3.insert({pt2, 2});
    points_3.insert({pt3, 3});

    printAssocContainer(points_3);

    return 0;
}
