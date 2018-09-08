#include <iostream>
#include <unordered_map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4}, pt5{5};
    std::unordered_multimap<Point, std::string, Point>  points;

    points.insert({{pt0, "india"}, {pt1, "poland"}, {pt1, "Austria"}, {pt3, "Germany"}, {pt1, "Czcech"}, {pt5, "Slovakia"}});
    printAssocContainer(points);

    /* 1. erase by position */
    auto iter = points.erase(points.begin());
    std::cout << "iter points to next element to the erased one: key: "<< iter->first << "\n";
    printAssocContainer(points);

    /* 2. erase by Key */
    size_t noOfElementsErased = points.erase(pt1);
    printAssocContainer(points);
    std::cout <<"Number of elements erased: " << noOfElementsErased << "\n";

    points.insert({{pt0, "Poland"}, {pt1, "Germany"}, {pt2, "Slovakia"}});
    printAssocContainer(points);

    /* 3. erase by range */
    iter = points.erase(std::next(points.begin(), 2), points.end());
    printAssocContainer(points);
    //std::cout << "iter points to next element to the erased one: key: "<< iter->first << "\n";

    return 0;
}
