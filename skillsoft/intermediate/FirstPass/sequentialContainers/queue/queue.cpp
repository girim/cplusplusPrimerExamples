#include <queue>
#include "../printContainerContents.hpp"
#include "../Cylinder.hpp"

int main()
{
    std::queue<int> firstQ;
    firstQ.push(1000);
    firstQ.push(4000);
    firstQ.push(9000);

    while(!firstQ.empty())
    {
        std::cout << firstQ.front() << std::endl;
        firstQ.pop();
    }

    std::queue<Cylinder> cylinders;
    cylinders.emplace();
    cylinders.emplace(6);
    cylinders.emplace(3,4);

    while(!cylinders.empty())
    {
        std::cout << cylinders.front() << std::endl;
        cylinders.pop();
    }

    return 0;
}