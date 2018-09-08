#include <iostream>
#include <unordered_map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3};
    std::unordered_multimap<Point, std::string, Point> points;
    points.emplace(pt0, "Poland");
    points.emplace(pt1, "Sweeden");
    points.emplace(pt1, "Denmark");
    points.emplace(pt2, "Germany");
    //points.emplace(pt2, "Austria");
    points.emplace(pt2, "Czech");
    points.emplace(pt3, "Netherland");

    printAssocContainer(points);

    std::cout << "Number of Buckets: " << points.bucket_count() << "\n";

    for(size_t bucket = 0; bucket < points.bucket_count(); ++bucket)
    {
        std::cout << "Bucket #" << bucket << " has " << points.bucket_size(bucket) << " elements" << "\n";
    }

    for(auto iter = points.begin(); iter != points.end(); ++iter)
    {
        std::cout << "item " << iter->first << " is in Bucket #" << points.bucket(iter->first) << "\n";
    }

    /* loadFactor = size/bucket */
    std::cout << "loadFactor: " << points.load_factor() << "\n";
    std::cout << "max loadFactor: " << points.max_load_factor() << "\n";
    
    return 0;
}
