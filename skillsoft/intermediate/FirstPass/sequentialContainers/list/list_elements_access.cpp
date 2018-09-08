#include <list>
#include "../printContainerContents.hpp"
#include "../Cylinder.hpp"

int main()
{
    Cylinder c1{}, c2{2,5};
    std::list<Cylinder> cylinders{c1, c2};

    printContainerContents(cylinders, "cylinders");

    /* std::list::front() --> returns lval reference to first element */
    Cylinder c3{1,7};
    cylinders.front() = c3;
    printContainerContents(cylinders, "cylinders");

    /* std::list::back()  --> returns lval reference to last element */
    Cylinder c4{3,5};
    cylinders.back() = c4; 
    printContainerContents(cylinders, "cylinders");
    
    return 0;
}