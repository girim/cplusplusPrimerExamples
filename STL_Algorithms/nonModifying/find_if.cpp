#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include "../point.hpp"
#include "../printSeqContainer.hpp"
#include "../printAssociativeContainer.hpp"

class Predicate
{
    public:
        bool operator()(const Point& point)
        {
            return (point.getY() > point.getX());
        }
};

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{4, 5};
    std::set<Point> points = {pt0, pt1, pt2, pt3};

    auto iter  = std::find_if(points.begin(), points.end(), [](const Point& point){
        return (point.getX() != point.getY());
    });

    if(iter != points.end())
    {
        std::cout << "Found item : " << *iter << "\n";
    }

    std::multimap<Point, std::string> points_0;
    points_0.insert({{pt0, "Aus"}, {pt1, "Ind"}, {pt0, "Eng"}, {pt2, "Rus"}});

    auto it = std::find_if(points_0.begin(), points_0.end(), [pt0](std::pair<const Point, std::string> item){
            return (item.first == pt0 && item.second == "Eng");
    });

    std::cout<< it->first << " " << it->second << "\n";

    iter = std::find_if(points.begin(), points.end(), Predicate{});
    if(iter != points.end()){
        std::cout << "Item found: " << *iter << "\n";
    }

    return 0;
}
