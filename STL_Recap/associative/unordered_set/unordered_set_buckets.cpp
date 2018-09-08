#include <iostream>
#include <unordered_set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::unordered_set<Point, Point> points = {pt0, pt1, pt2, pt3};

    printAssocContainer(points);

    /* Bucket Count */
    std::cout << "Bucket Count: " << points.bucket_count() << '\n';

    /* Bucket Size */
    for(auto bucket = 0; bucket < points.bucket_count(); bucket++)
    {
        std::cout << "Bucket #" << bucket << " has: " << points.bucket_size(bucket) << " items" << '\n';
    }

    /* Buckets */
    for(auto point : points)
    {
        std::cout << "Item " << point << " is in Bucket #" << points.bucket(point) << "\n";
    }


    return 0;
}
