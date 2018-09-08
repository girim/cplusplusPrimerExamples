#include <iostream>
#include <unordered_set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

class hasherClass
{
    public:
        std::size_t operator()(const Point& pt) const
        {
            std::size_t hashX = std::hash<unsigned>()(pt.getX());
            std::size_t hashY = std::hash<unsigned>()(pt.getY());

            return (hashX ^ hashY);
        }
};

class comparePoints
{
    public:
        bool operator()(const Point& pt1, const Point& pt2) const
        {
            return (pt1.getX() == pt2.getX());
        }
};

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4}, pt5{4, 2};
    std::unordered_set<Point, hasherClass, comparePoints> points(8);
    points.insert({pt0, pt1, pt2, pt3, pt4, pt5});

    printAssocContainer(points);

    return 0;
}
