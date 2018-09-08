#include <map>
#include <iostream>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1, 1}, pt2{2, 2}, pt3{3, 3};
    std::multimap<Point, std::string> points = {{pt1, "c++"}};
    /* 1. insert single value */
    auto iter = points.insert({pt0, "c"});
    std::cout << "return value: key: " << iter->first << " value: " << iter->second << "\n";

    points.insert({pt2, "javaScript"});
    points.insert({pt3, "python"});
    points.insert({pt2, "javaScript"});

    printAssocContainer(points);

    /* 2. range  */
    std::multimap<Point, std::string> copyOfPoints;
    copyOfPoints.insert(points.begin(), points.end());
    printAssocContainer(copyOfPoints);

    /* 3. initialier_list */
    std::multimap<Point, std::string> points_0 = {{pt0, "c++"}, {pt2, "JavaScript"},{pt3, "Python"}};
    printAssocContainer(points_0);

    /* 4. single value with hint */
    points.insert(points.begin(), {pt0, "C++"});
    printAssocContainer(points);

    return 0;
}

