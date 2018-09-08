#include <iostream>
#include <unordered_map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2};
    std::unordered_map<Point, std::string, Point> points = {{pt0, "Center"}, {pt1, "OneUnit"}, {pt2, "TwoUnit"}};

    printAssocContainer(points);

    /* [begin, end) */
    for(std::unordered_map<Point, std::string, Point>::iterator iter = points.begin(); iter != points.end(); ++iter)
    {
        std::cout << "constKey: " << iter->first << " Value: " << iter->second << "\n";

        if(iter->second == "Center")
        {
            iter->second = "Origin";
            //iter->first = pt1;
        }
    }
    printAssocContainer(points);

    /* [cbegin, cend) */
    for(std::unordered_map<Point, std::string, Point>::const_iterator iter = points.cbegin(); iter != points.cend(); ++iter)
    {
        std::cout << "constKey: " << iter->first << " constValue: " << iter->second << "\n";
    }

    return 0;
}
