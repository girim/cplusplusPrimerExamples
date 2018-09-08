#include <list>
#include "../printContainerContents.hpp"
#include "../Cylinder.hpp"

int main()
{
    std::list<double> fractions{1.1, 1.2, 1.3, 1.4, 1.3, 1.3};
    printContainerContents(fractions, "fractions");

    fractions.remove(1.3);
    fractions.remove(1.2);
    printContainerContents(fractions, "fractions");

    Cylinder c1{}, c2{}, c3{2,4};
    std::list<Cylinder> cylinders{c1, c2, c3};
    printContainerContents(cylinders, "cylinders");

    cylinders.remove(c1);
    printContainerContents(cylinders, "cylinders");

    return 0;
}