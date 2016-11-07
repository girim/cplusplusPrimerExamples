#include <deque>
#include "printContainerContents.hpp"

int main()
{
    std::deque<int> firstQue{1,1,1,1};
    std::deque<int> secondQue{2,2,2,2};
    std::deque<int> thirdQue{1,1,1,1};

    if(firstQue == thirdQue)
        std::cout << "firstQue is Equal to thirdQue " << std::endl;
    
    if(firstQue != secondQue)
        std::cout << "firstQue is Not Equal to secondQue " << std::endl;

    if(firstQue < secondQue)
        std::cout << "firstQue is less than secondQue " << std::endl;

    if(secondQue > thirdQue)
        std::cout << "firstQue is greater than secondQue " << std::endl;

    if(secondQue <= secondQue)
        std::cout << "firstQue is less than or Equal secondQue " << std::endl;

    if(secondQue >= thirdQue)
        std::cout << "firstQue is greater than or Equal to secondQue " << std::endl;

    return 0;
}