#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"
#include "../printSeqContainer.hpp"

void AddTwo(Point& point)
{
    point.setX((point.getX() + 2));
    point.setY((point.getY() + 2));
}

class LeftShift
{
    public:
        void operator()(Point& point)
        {
            point.setX(point.getX() << 2);
            point.setY(point.getY() << 2);
        }
};

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::vector<Point> points{pt0, pt1, pt2, pt3};
    //printAssocContainer(points);

    unsigned multiplier = 2;
    /* Using Lambda Function */
    auto fn = std::for_each(points.begin(), points.end(), [multiplier](Point& point){
            point.setX(point.getX() * multiplier);
            point.setY(point.getY() * multiplier);
    });

    printSequentialContainer(points);

    /* Using Function */
    std::for_each(points.begin(), points.end(), AddTwo);
    printSequentialContainer(points);

    /* Using Function object */
    std::for_each(points.begin(), points.end(), LeftShift{});
    printSequentialContainer(points);

    /* Associative container with for-each */
    std::map<unsigned, Point> points_0;
    points_0.insert({{1, pt0}, {2, pt1}, {3, pt2}, {4, pt3}});
    printAssocContainer(points_0);

    std::for_each(points_0.begin(), points_0.end(), [&points_0](std::pair<unsigned, Point> item){
        item.second.setX((item.second.getX() * 3));
        points_0[item.first] = item.second;
    });
    printAssocContainer(points_0);

    return 0;
}
