#include <list>
#include "../printContainerContents.hpp"
#include "../Cylinder.hpp"

int main()
{
    std::list<Cylinder> cylinders;
    cylinders.emplace_back();     /* constuct with defualt arguments */
    cylinders.emplace_back(3);    /* construct with 1 default arguments */
    cylinders.emplace_back(4,6);
    printContainerContents(cylinders, "cylinders");

    return 0;
}