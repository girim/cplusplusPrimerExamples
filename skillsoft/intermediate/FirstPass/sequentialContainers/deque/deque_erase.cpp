#include <deque>
#include "printContainerContents.hpp"
#include "../Plane.hpp"

std::ostream& operator<<(std::ostream& os, const Plane& plane)
{
    os << "{ length: " << plane.getLength() <<  " width: " << plane.getWidth() \
        << " Area: " << plane.getAreaOfPlane() << " }";

    return os;
}

int main()
{
    std::deque<int> numbers{1, 2, 3, 4, 5};
    printContainerContents(numbers, "numbers_1");

    //1. erase(position)
    /* auto iter = numbers.erase(numbers.begin()+2);
    std::cout << "Returned iter points to : " << *iter << std::endl;
    printContainerContents(numbers, "numbers_2"); */

    //2. Using Range erase(begin, end)
    auto it = numbers.erase(numbers.begin()+2, numbers.end());
    std::cout << "Returned iter points to : " << *it << std::endl;
    printContainerContents(numbers, "numbers_3");

    it = numbers.erase(numbers.end()-1);
    std::cout << "Returned iter points to : " << *it << std::endl;
    printContainerContents(numbers, "numbers_5");

    numbers.assign({1,2,3,4,5});
    printContainerContents(numbers, "numbers_6");

    auto iters = numbers.erase(numbers.begin()+1, numbers.begin()+3);
    std::cout << "Returned iter points to : " << *iters << std::endl;
    printContainerContents(numbers, "numbers_7");

    return 0;
}