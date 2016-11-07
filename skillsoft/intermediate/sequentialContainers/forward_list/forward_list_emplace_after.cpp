#include <forward_list>
#include "../printContainerContents.hpp"
#include "../Plane.hpp"

std::ostream& operator<<(std::ostream& os, const Plane& plane)
{
    os << "{ length: " << plane.getLength() <<  " width: " << plane.getWidth() \
        << " Area: " << plane.getAreaOfPlane() << " }";

    return os;
}

int main()
{
    std::forward_list<int> numbers{0};
    printContainerContents(numbers, "numbers");

    auto iter = numbers.emplace_after(numbers.before_begin(), 10);
    printContainerContents(numbers, "numbers");

    iter = numbers.emplace_after(iter, 40);
    printContainerContents(numbers, "numbers");

    iter = numbers.emplace_after(iter, 60);
    printContainerContents(numbers, "numbers");

    numbers.emplace_after(iter, 70);
    printContainerContents(numbers, "numbers");
    
    return 0;
}



