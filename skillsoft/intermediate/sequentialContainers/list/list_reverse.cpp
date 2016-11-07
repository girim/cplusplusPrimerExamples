#include <list>
#include <string>
#include "../printContainerContents.hpp"

int main()
{
    std::list<std::string> teams{"DD", "CSK", "MI","RR","SRH", "KXIP", "RCB"};
    printContainerContents(teams, "teams");

    teams.reverse();
    printContainerContents(teams, "teams");

    return 0;
}