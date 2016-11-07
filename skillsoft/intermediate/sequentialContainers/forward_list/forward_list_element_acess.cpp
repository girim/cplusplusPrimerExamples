#include <forward_list>
#include <string>
#include "../printContainerContents.hpp"
#include "../Plane.hpp"

int main()
{
    std::forward_list<std::string> teams{"CSK", "RCB", "RR", "DD"};
    printContainerContents(teams, "teams");

    /* front returns 'lvalue reference' to the first element in the list */
    teams.front() = "SRH";
    printContainerContents(teams, "teams");

    Plane p1{}, p2{1,1}, p3{2,2};
    std::forward_list<Plane> planes{p1, p2};
    printContainerContents(planes, "planes");

    planes.front() = p3;
    printContainerContents(planes, "planes");

    return 0;
}