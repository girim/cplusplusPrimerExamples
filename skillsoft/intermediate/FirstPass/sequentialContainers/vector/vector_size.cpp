#include <vector>
#include "Plane.hpp"

int main()
{
    //std::vector::size -- returns the number of elements stored in the vector
    std::vector<int> numbers{9, 8, 7, 6};
    std::cout << "size of the vector numbers is : " << numbers.size() << std::endl;

    Plane p1{1,2}, p2{3,4}, p3{4,5};
    std::vector<Plane> planeList{p1, p2, p3};
    std::cout << "size of the vector planeList is : " << planeList.size() << std::endl;
     
    return 0;
}