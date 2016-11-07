#include <list>
#include "../printContainerContents.hpp"
#include "../Cylinder.hpp"

int main()
{
    Cylinder c1{}, c2{1,7}, c3{5,8};
    std::list<Cylinder> cylinders{c1, c2, c3};

    printContainerContents(cylinders, "cylinders");
    std::cout << "size of cylinders : " << cylinders.size() << std::endl;

    cylinders.resize(1);
    printContainerContents(cylinders, "cylinders");
    std::cout << "size of cylinders : " << cylinders.size() << std::endl;
    
    return 0;
}