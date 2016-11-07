#include <list>
#include "../printContainerContents.hpp"
#include "../Cylinder.hpp"

int main()
{
    std::list<Cylinder> cylinders;
    cylinders.emplace_front();
    cylinders.emplace_front(9);
    cylinders.emplace_front(2,6);

    printContainerContents(cylinders, "cylinders");
    
    return 0;
}