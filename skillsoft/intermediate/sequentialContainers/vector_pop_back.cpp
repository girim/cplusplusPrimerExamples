#include <vector>
#include "printVectorContents.hpp"
#include "Plane.hpp"

std::ostream& operator<<(std::ostream& os, const Plane& plane)
{
    os << "{ length: " << plane.getLength() <<  " width: " << plane.getWidth() \
        << " Area: " << plane.getAreaOfPlane() << " }";

    return os;
}

int main()
{
    std::vector<int> numbers{1,2,3,4};

    std::cout << "Size of numbers before: " << numbers.size() << std::endl;
    numbers.pop_back();
    numbers.pop_back();
    std::cout << "Size of numbers after: " << numbers.size() << std::endl;

    printVectorContents(numbers, "numbers");

    Plane p1{1,2}, p2{4,5}, p3{6,9};
    std::vector<Plane> planelist{p1, p2, p3};
    printVectorContents(planelist, "planelist_before");

    planelist.pop_back();   //removes the element and destroys the object
    printVectorContents(planelist, "planelist_after");

    std::vector<int> oddNumbers{1,3,5,7};

    int sum  = 0;
    while(!oddNumbers.empty())
    {
        sum += oddNumbers.back();
        oddNumbers.pop_back();
    }

    std::cout << "Sum of odd numbers is : " << sum << " and size of oddNumbers vec is " << oddNumbers.size() << std::endl;

    return 0;
}