#include <iostream>
#include <unordered_set>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1, 3}, pt2{2}, pt3{3, 1}, pt4{4}, pt5{5}, pt6{6};
    std::unordered_set<Point, Point> points = {pt0, pt1, pt2, pt3};

    printAssocContainer(points);

    std::cout <<"No of buckets: " << points.bucket_count() << "\n";
    std::cout <<"Load factor: " << points.load_factor() << "\n";
    points.emplace(pt4);
    points.emplace(pt5);
    points.emplace(pt6);
    std::cout <<"No of buckets: " << points.bucket_count() << "\n";
    std::cout <<"Load factor: " << points.load_factor() << "\n";

    for(auto bucket = 0; bucket < points.bucket_count(); ++bucket)
    {
        std::cout << "Bucket #" << bucket  << " contains " << points.bucket_size(bucket) << " items" << "\n"; 
    }

    for(auto point : points)
    {
        std::cout << "item " << point << " is in bucket #" << points.bucket(point) << "\n";
    }

    /* rehash */
    points.rehash(12);
    std::cout <<"No of buckets: " << points.bucket_count() << "\n";
    std::cout <<"Load factor: " << points.load_factor() << "\n";


    for(auto bucket = 0; bucket < points.bucket_count(); ++bucket)
    {
        std::cout << "Bucket #" << bucket  << " contains " << points.bucket_size(bucket) << " items" << "\n"; 
    }

    for(auto point : points)
    {
        std::cout << "item " << point << " is in bucket #" << points.bucket(point) << "\n";
    }

    return 0;
}
