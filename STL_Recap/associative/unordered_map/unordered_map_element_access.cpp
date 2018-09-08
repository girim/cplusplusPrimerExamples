#include <iostream>
#include <unordered_map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    /* 1. using the [] operator -> returns lvalue reference to element */
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::unordered_map<Point, std::string, Point> points = {{pt0, "one"}, {pt1, "two"}, {pt2, "three"}};
    printAssocContainer(points);

    std::cout << "Element with key pt0 is: " << points[pt0] << "\n";
    /* If key does not exist then unordered_map crates key and constructs element using default constructor */
    std::cout << "Element with key pt3 is: " << points[pt3] << "\n";
    printAssocContainer(points);

    points[pt3] = "Four";
    printAssocContainer(points);

    std::unordered_map<std::string, Point> points_0 = {{"one", pt0}, {"two", pt1}, {"three", pt2}};
    printAssocContainer(points_0);

    std::cout << points_0["four"] << "\n";
    printAssocContainer(points_0);

    /* 2. at --> throws out_of_range exception */
    std::cout << "Value for key one is: " << points_0.at("one") << "\n";

    
    try
    {
        points_0.at("five");
    }
    catch(const std::out_of_range& e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}
