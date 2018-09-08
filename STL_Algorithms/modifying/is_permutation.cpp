#include <iostream>
#include <algorithm>
#include <set>
#include "../point.hpp"

int main(int argc, char const *argv[])
{
    Point pt0{}, pt1{1}, pt2{2}, pt3{3}, pt4{4};
    std::set<Point> firstSet = {pt0, pt3, pt1, pt2}; //, pt4};
    std::set<Point> secondSet = {pt0, pt1, pt2, pt3, pt2};

    auto result =  std::is_permutation(firstSet.begin(), firstSet.end(), secondSet.begin());
    std::cout << "Is permutation: " << std::boolalpha << result << "\n";


    return 0;
}
