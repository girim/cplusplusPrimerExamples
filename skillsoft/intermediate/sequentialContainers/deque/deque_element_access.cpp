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
    std::deque<int> numbers{1,2,3,4,5,6};
    printContainerContents(numbers, "numbers");
    /* 1. operator[n] --> do not throw out_of_range exception if 'n' is out of bound 
        returns 'reference' to the element */
    
    numbers[0] = 9;  //numbers[0] --> returns 'reference'(lvalue ref) to the first element
    printContainerContents(numbers, "numbers");

    /* 2. std::deque::at --> thows the out_of_range exception is 'n' is out of bound
        returns 'reference' to the element  */
    numbers.at(4) = 999;
    printContainerContents(numbers, "numbers");

    try
    {
        numbers.at(7);
    }
    catch(std::out_of_range& error)
    {
        std::cout << "Out of Bound exception..." << error.what() << std::endl;
    }

    /* 3. std::deque::front --> returns 'reference' to the first element*/
    numbers.front() = 0;
    printContainerContents(numbers, "numbers");

    /* 4. std::deque::back --> returns 'reference' to the last element */
    numbers.back() = 0;
    printContainerContents(numbers, "numbers");

    return 0;
}