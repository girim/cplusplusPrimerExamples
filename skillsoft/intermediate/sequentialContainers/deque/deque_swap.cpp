#include <deque>
#include "printContainerContents.hpp"

int main()
{
    std::deque<float> firstQueue{2.0, 4.0, 5.0, 6.0};
    std::deque<float> secondQueue{0.0, 0.0};

    printContainerContents(firstQueue, "firstQueue_before_swap");
    printContainerContents(secondQueue, "secondQueue_before_swap");

    firstQueue.swap(secondQueue);

    printContainerContents(firstQueue, "firstQueue_after_swap");
    printContainerContents(secondQueue, "secondQueue_after_swap");

    return 0;
}