#include <deque>
#include "../Plane.hpp"
#include "printContainerContents.hpp"

std::ostream& operator<<(std::ostream& os, const Plane& plane)
{
    os << "{ length: " << plane.getLength() <<  " width: " << plane.getWidth() \
        << " Area: " << plane.getAreaOfPlane() << " }";

    return os;
}

int main()
{
    /* std::deque::insert(position, value(s)):
    The deque container is extended by inserting new elements before the element at the specified position
    
    Return type: iterator to the first element inserted
     */

    std::deque<int> oddNumbers{1};
    printContainerContents(oddNumbers, "oddNumbers_1");
    
    //1. Using single value --> insert(position, value)
    auto iter = oddNumbers.insert(oddNumbers.begin(), 10);
    printContainerContents(oddNumbers, "oddNumbers_2");
    std::cout << "Returned iter points to : " << *iter << std::endl;

    //2. Using fill --> insert(position, n, value)
    iter = oddNumbers.insert(oddNumbers.begin()+1, 4, 0);
    printContainerContents(oddNumbers, "oddNumbers_2");
    std::cout << "Returned iter points to : " << *iter << std::endl;

    //3. Using range --> insert(begin, end)
    int numbers[] = {4,5,6,7};
    iter = oddNumbers.insert(oddNumbers.end()-1, numbers, (numbers + sizeof(numbers)/sizeof(int)));
    printContainerContents(oddNumbers, "oddNumbers_3");
    std::cout << "Returned iter points to : " << *iter << std::endl;

    //4. Using initializer_list
    iter = oddNumbers.insert(oddNumbers.begin()+1, {4, 4, 4});
    printContainerContents(oddNumbers, "oddNumbers_4");
    std::cout << "Returned iter points to : " << *iter << std::endl;

    Plane p1{}, p2{}, p3{2,2};
    std::deque<Plane> planeList{p1, p2};
    printContainerContents(planeList, "planeList");

    auto it = planeList.insert(planeList.begin()+1, p3);
    printContainerContents(planeList, "planeList");
    std::cout << "Returned iter points to : " << *it << std::endl;


    return 0;
}