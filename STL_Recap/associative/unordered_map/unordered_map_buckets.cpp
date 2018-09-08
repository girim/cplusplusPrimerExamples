#include <iostream>
#include <unordered_map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4};
    std::unordered_map<Point, unsigned, Point> points = {{pt0, 20}, {pt1, 40}, {pt2, 60}, {pt3, 80}, {pt4, 90}};
    printAssocContainer(points);

    /* bucket_count --> returns the no of buckets(slots) */
    size_t noOfBuckets = points.bucket_count();
    std::cout << "Number of buckets: " << noOfBuckets << "\n";
    printSizeOfEachBuckets(points);
    printTheItemsInEachBuckets(points);

    std::cout << "load factor (size/buckets) : " << points.load_factor() << "\n";
    std::cout << "maximum load factor: " << points.max_load_factor() << "\n";

    Point pt5{5}, pt6{6}, pt7{7}, pt8{8}, pt9{9};
    points.emplace(pt7, 70);
    points.emplace(pt6, 100);
    points.emplace(pt5, 120);
    points.emplace(pt8, 140);
    points.emplace(pt9, 160);

    noOfBuckets = points.bucket_count();
    std::cout << "load factor (size/buckets) : " << points.load_factor() << "\n";
    std::cout << "Number of buckets: " << noOfBuckets << "\n";
    printSizeOfEachBuckets(points);
    printTheItemsInEachBuckets(points);

    return 0;
}
