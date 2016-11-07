#include <list>
#include "../printContainerContents.hpp"
#include "../Cylinder.hpp"

bool lessThanTwo(const int& number)
{
    return (number < 4);
}

class greaterThanSix
{
    public:
        bool operator()(const int& number)
        {
            return (number > 6);
        }
};

int main()
{
    std::list<int> numbers{1,2,3,4,5,6,7,8,9};
    printContainerContents(numbers, "numbers_1");

    numbers.remove_if([](const int& number){
        return (number % 2 != 0);
    });
    printContainerContents(numbers, "numbers_1");

    numbers.remove_if(lessThanTwo);
    printContainerContents(numbers, "numbers_1");

    numbers.remove_if(greaterThanSix());
    printContainerContents(numbers, "numbers_1");

    Cylinder c1{}, c2{1,4}, c3{2,2};
    std::list<Cylinder> cylinders{c1, c2, c3};

    printContainerContents(cylinders, "cylinders");
    cylinders.remove_if([](const Cylinder& cylinder){
        return (cylinder.surfaceArea() < 15);
    });
    printContainerContents(cylinders, "cylinders");

    return 0;
}