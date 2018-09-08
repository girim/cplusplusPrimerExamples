#include <iostream>
#include <unordered_map>
#include "../point.hpp"
#include "../printAssociativeContainer.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1, 2}, pt2{3, 4}, pt3{5, 6}, pt4{7, 8};
                    /*<Key, Value, HashFunction>  */
    std::unordered_map<Point, unsigned, Point> points = {{pt0, 1}, {pt1, 2}, {pt2, 3}, {pt3, 5}, {pt4, 6}};

    printAssocContainer(points);

    std::cout << "loadFactor: " << points.load_factor() << "\n";
    std::cout << "Bucket count: " << points.bucket_count() << "\n";

    for(auto bucketNumber = 0; bucketNumber < points.bucket_count(); ++bucketNumber)
    {
        std::cout << "Number of elements in Bucket[" << bucketNumber <<"] is: " << points.bucket_size(bucketNumber) << "\n"; 
    }

    for(auto iter = points.begin(); iter != points.end(); ++iter)
    {
        std::cout << "Item " << iter->first << " is in Bucket: " << points.bucket(iter->first) << "\n";
    }

    return 0;
}
