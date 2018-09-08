#include <forward_list>
#include "../printContainerContents.hpp"
#include "../Plane.hpp"

bool isSingleDigit(const int& number)
{
    return (number < 10);
}

class isEven
{
    public:
        bool operator()(const int& number)
        {
            return (number % 2 == 0);
        }
};

int main()
{
    std::forward_list<int> numbers{10,1,4,5,90,40,2};
    printContainerContents(numbers, "numbers_1");

    /* Predicate can be normal function */
    numbers.remove_if(isSingleDigit);
    printContainerContents(numbers, "numbers_2");

    /* Predicate can be function object */
    numbers.remove_if(isEven());
    printContainerContents(numbers, "numbers_3");

    Plane p1{}, p2{}, p3{1,4}, p4{2,2};
    std::forward_list<Plane> planeList{p1, p2, p3, p4};
    printContainerContents(planeList, "planeList");

    /* Predicate can be Lambda function */
    planeList.remove_if([](const Plane& plane){
        return (plane.getAreaOfPlane() == 0);
    });
    printContainerContents(planeList, "planeList");

    return 0;
}