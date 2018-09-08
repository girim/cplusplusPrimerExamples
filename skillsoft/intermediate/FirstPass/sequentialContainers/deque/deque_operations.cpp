#include <deque>
#include "printContainerContents.hpp"

int main()
{
    std::deque<int> que;
    que.push_front(1);
    printContainerContents(que, "push_front");

    que.push_front(2);
    printContainerContents(que, "push_front");

    que.push_front(3);
    printContainerContents(que, "push_front");

    que.push_back(4);
    printContainerContents(que, "push_back");

    que.push_back(5);
    printContainerContents(que, "push_back");

    que.pop_front();
    printContainerContents(que, "pop_front");

    que.pop_back();
    printContainerContents(que, "pop_back");

    que.pop_front();
    printContainerContents(que, "pop_front");

    que.pop_back();
    printContainerContents(que, "pop_back");
    
    que.pop_back();
    printContainerContents(que, "pop_back");
    
    return 0;
}
