#include <iostream>
#include <unordered_map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::unordered_multimap<Point, std::string, Point> points;

    /* 1. emplace -->returns the iter to the emplaced element */
    auto iter  = points.emplace(pt0, "India");
    std::cout << "emplaced element with key : " << iter->first << " value: " << iter->second << "\n";

    points.emplace(pt1, "Germany");
    points.emplace(pt2, "Austria");
    points.emplace(pt2, "Hungary");
    points.emplace(pt3, "Slovakia");

    printAssocContainer(points);

    /* 2. emplace_hint  */
    Point pt4{4};
    points.emplace_hint(points.begin(), pt4, "Poland");
    printAssocContainer(points);

    /* 3. insert  */
    std::unordered_multimap<Point, unsigned, Point> points_0;
    /* insert single element */
    auto itrToItem = points_0.insert({pt0, 1});
    std::cout << "Element inserted: key " << itrToItem->first << " value: " << itrToItem->second << "\n";
    itrToItem = points_0.insert({pt2, 2});
    std::cout << "Element inserted: key " << itrToItem->first << " value: " << itrToItem->second << "\n";
    points_0.insert({pt3, 3});
    points_0.insert({pt1, 4});
    printAssocContainer(points_0);

    /* insert single element with hint */
    itrToItem = points_0.insert(points_0.begin(), {pt0, 0});
    std::cout << "Element inserted: key " << itrToItem->first << " value: " << itrToItem->second << "\n";
    printAssocContainer(points_0);

    std::pair<Point, unsigned> pt5 = std::make_pair(pt4, 10);
    points_0.insert(std::move(pt5));
    printAssocContainer(points_0);

    std::cout << pt4 << "\n";

    /* insert using the range */
    std::unordered_multimap<Point, unsigned, Point> points_1;
    points_1.insert(std::next(points_0.begin(), 3), points_0.end()); 
    printAssocContainer(points_1);

    /* insert using the initializer_list */
    points_1.insert({{pt4, 8}, {pt2, 7}});
    printAssocContainer(points_1);

    return 0;
}
