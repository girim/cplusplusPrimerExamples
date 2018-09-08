#include <list>
#include "../printContainerContents.hpp"
#include "../Cylinder.hpp"

int main()
{
    std::list<double> fractions;
    fractions.push_back(1.1);
    fractions.push_front(1.2);
    fractions.push_back(1.3);
    fractions.push_front(1.4);
    fractions.push_front(1.5);
    fractions.push_back(1.7);

    printContainerContents(fractions, "fractions");

    fractions.pop_back();
    printContainerContents(fractions, "fractions");
    fractions.pop_front();
    printContainerContents(fractions, "fractions");

    fractions.pop_back();
    fractions.pop_front();
    printContainerContents(fractions, "fractions");

    Cylinder c1{}, c2{1,2}, c3{3,4};
    std::list<Cylinder> cylinders;
    cylinders.push_back(c1);
    cylinders.push_front(c2);
    printContainerContents(cylinders, "cylinders");
    cylinders.push_back(c3);
    printContainerContents(cylinders, "cylinders");

    cylinders.pop_back();
    cylinders.pop_front();
    printContainerContents(cylinders, "cylinders");

    return 0;
}