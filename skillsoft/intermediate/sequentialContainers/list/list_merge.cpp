#include <list>
#include "../printContainerContents.hpp"
#include "../Cylinder.hpp"

int main()
{
    std::list<std::string> groupA{"CSK", "DD", "RCB"};
    std::list<std::string> groupB{"RR", "MI", "SRH", "KXIP"};

    groupA.sort();
    groupB.sort();

    groupA.merge(groupB);
    printContainerContents(groupA, "groupA");
    printContainerContents(groupB, "groupB");

    std::list<double> firstPart{3.1, 2.2, 2.9};
    std::list<double> secondPart{3.7, 7.1, 1.4};
    firstPart.sort();
    secondPart.sort();

    firstPart.merge(secondPart, [](const double& lhs, const double& rhs){
        return (static_cast<int>(lhs) < static_cast<int>(rhs));
    });
    printContainerContents(firstPart, "firstPart");
    printContainerContents(secondPart, "secondPart");

    return 0;
}