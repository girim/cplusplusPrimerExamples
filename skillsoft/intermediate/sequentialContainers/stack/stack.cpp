#include <stack>
#include <vector>
#include "../printContainerContents.hpp"
#include "../Cylinder.hpp"

int main()
{
    std::stack<int> first;
    first.push(10);
    first.push(20);
    first.push(30);

    while(!first.empty())
    {
        std::cout << first.top() << " ";
        first.pop();
    }
    std::cout << "\n";

    std::stack<int, std::vector<int>> second;
    second.push(11);
    second.push(12);
    second.push(13);

    while(!second.empty())
    {
        std::cout << second.top() << " ";
        second.pop();
    }
    std::cout << "\n";

    std::vector<int> vec{1,2,3,4};
    std::stack<int, std::vector<int>> third(vec);

    while(!third.empty())
    {
        std::cout << third.top() << " ";
        third.pop();
    }
    std::cout << "\n";

    std::stack<Cylinder> stackOfCylinder;
    stackOfCylinder.emplace();
    stackOfCylinder.emplace(4);
    stackOfCylinder.emplace(8,9);

    while(!stackOfCylinder.empty())
    {
        std::cout << stackOfCylinder.top() << std::endl;
        stackOfCylinder.pop();
    }

    return 0;
}