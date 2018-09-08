#include <forward_list>
#include "../printContainerContents.hpp"
#include "../Plane.hpp"
#include <string>

int main()
{
    std::forward_list<std::string> teams{"CSK", "RR", "RCB", "DD", "SRH"};
    printContainerContents(teams, "teams");

    teams.remove("RR");
    printContainerContents(teams, "teams");

    Plane p1{}, p2{}, p3{1,1}, p4{4,4};
    std::forward_list<Plane> planeList{p1,p2,p3,p4};
    printContainerContents(planeList, "planeList");

    planeList.remove(p1);
    printContainerContents(planeList, "planeList");

    return 0;
}