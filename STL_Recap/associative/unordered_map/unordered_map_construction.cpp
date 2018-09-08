#include <unordered_map>
#include <iostream>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    /* 1. empty constructor */
    std::unordered_map<unsigned, std::string> points;
    points.emplace(2, "C++");
    points.emplace(1, "JavaScript");
    points.emplace(3, "Python");
    points.emplace(4, "Java");

    printAssocContainer(points);

    /* 2. Range constructor*/
    std::unordered_map<unsigned, std::string> points_0(points.begin(), points.end());
    printAssocContainer(points_0);

    /* 3. copy constructor */
    std::unordered_map<unsigned, std::string> points_1(points_0);
    printAssocContainer(points_1);

    /* 4. move constructor */
    std::unordered_map<unsigned, std::string> points_2(std::move(points_1));
    printAssocContainer(points_1);
    printAssocContainer(points_2);

    /* 5. Initializer_list */
    std::unordered_map<std::string, std::string> points_3();

    return 0;
}
