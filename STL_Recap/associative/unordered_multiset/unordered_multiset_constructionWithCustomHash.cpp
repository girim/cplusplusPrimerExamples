#include <iostream>
#include <unordered_set>
#include <functional>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

class HashClass
{
    public:
        std::size_t operator()(const Point& pt) const
        {
            std::size_t hashX = std::hash<unsigned>()(pt.getX());
            std::size_t hashY = std::hash<unsigned>()(pt.getY());

            return (hashX ^ hashY);
        }
};

class ComparatorClass
{
    public:
        bool operator()(const Point& pt1, const Point& pt2) const
        {
            return (pt1.getY() == pt2.getY());
        }
};

std::size_t hashFunction(const Point& pt)
{
    std::cout << "hash function callled " << "\n";
    std::size_t hashX = std::hash<unsigned>()(pt.getX());
    std::size_t hashY = std::hash<unsigned>()(pt.getY());

    std::cout << "hashCode# " << ((hashX << 2) ^ (hashY << 1)) << "\n";
    return ((hashX << 2) ^ (hashY << 1));
}

bool comparatorFunction(const Point& pt1, const Point& pt2)
{
    std::cout << "comparator function callled " << "\n";
    return (pt1.getX() == pt2.getY());
}

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2};
    /* Using 'funtion pointers' */
    std::unordered_multiset<Point, std::size_t(*)(const Point&), bool(*)(const Point&, const Point&)> points_0(5, hashFunction, comparatorFunction);

    points_0.emplace(pt0);
    points_0.emplace(pt0);
    points_0.emplace(pt1);
    points_0.emplace(pt2);

    printAssocContainer(points_0);

    /* Using 'function Objects' */
    std::unordered_multiset<Point, HashClass, ComparatorClass> points_1 = {pt0, pt1, pt1, pt2};
    printAssocContainer(points_1);

    /* Using 'Lambda functions' */
    auto hashLambda =  [](const Point& pt){
            std::size_t hashX = std::hash<unsigned>()(pt.getX());
            std::size_t hashY = std::hash<unsigned>()(pt.getY());

            return (hashX ^ hashY);
    };

    auto compareLambda = [](const Point& pt1, const Point& pt2){
         return (pt1.getX() == pt2.getY());
    };

    std::unordered_multiset<Point, std::function<std::size_t(const Point&)>, std::function<bool(const Point& , const Point&)> > points_2(5, hashLambda, compareLambda);
    points_2.emplace(pt0);
    points_2.emplace(pt1);
    points_2.emplace(pt1);
    points_2.emplace(pt2);

    printAssocContainer(points_2);

    return 0;
}
