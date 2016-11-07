#include <list>
#include <string>
#include "../printContainerContents.hpp"
#include "../Cylinder.hpp"

int main()
{
    std::list<std::string> teams{"DD", "MI", "CSK", "DD","SRH", "RCB","MI"};
    printContainerContents(teams, "teams");

    teams.sort();
    printContainerContents(teams, "teams");
    
    teams.unique();
    printContainerContents(teams, "teams");

    Cylinder c1{}, c2{2,4}, c3{3,4}, c4{5,6};
    std::list<Cylinder> cylinders{c4, c2, c1, c3};
    printContainerContents(cylinders, "cylinders");

    cylinders.sort();
    printContainerContents(cylinders, "cylinders_sorted");

    cylinders.unique([](const Cylinder& lhs, const Cylinder& rhs){
        return (lhs.getRadius() == rhs.getRadius());
    });
    printContainerContents(cylinders, "cylinders_unique");


    return 0;
}
