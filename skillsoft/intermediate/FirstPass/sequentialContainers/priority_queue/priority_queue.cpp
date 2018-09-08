#include <queue>
#include "../Cylinder.hpp"

int main()
{
    std::priority_queue<int> pqueue;
    pqueue.push(10);
    pqueue.push(25);
    pqueue.push(100);
    pqueue.push(50);

    while(!pqueue.empty())
    {
        std::cout << pqueue.top() << std::endl;
        pqueue.pop();
    }

    std::priority_queue<Cylinder> cylinders;
    cylinders.emplace();
    cylinders.emplace(2,4);
    cylinders.emplace(7);

    while(!cylinders.empty())
    {
        std::cout << cylinders.top() << std::endl;
        cylinders.pop();
    }

    return 0;
}