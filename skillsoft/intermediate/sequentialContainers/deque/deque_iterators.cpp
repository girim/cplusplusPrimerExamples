#include <deque>
#include "printContainerContents.hpp"

int main()
{
    std::deque<int> evenNumbers{2,4,6,8};

    /* 1. begin(), end() */
    for(std::deque<int>::iterator iter = evenNumbers.begin(); iter != evenNumbers.end(); ++iter)
    {
        std::cout << *iter << " ";
        if (*iter == 4)
            *iter = 100;
    }
    std::cout << "\n";
    
    /* 2. cbegin(), cend() */
    for(std::deque<int>::const_iterator citer = evenNumbers.cbegin(); citer != evenNumbers.cend(); ++citer)
    {
        std::cout << *citer << " ";
        if (*citer == 100)
        {
            //*citer = 4;   //cannot assign as the 'citer' is read-only 
        }
    }
    std::cout << "\n";

    /* 3. rbegin(), rend() */
    for(std::deque<int>::reverse_iterator riter = evenNumbers.rbegin(); \
            riter != evenNumbers.rend(); ++riter)
    {
        if (*riter == 100)
            *riter = 4;
        std::cout << *riter << " ";
    }
    std::cout << "\n";

    /* 4. crbegin(), crend() */
    for(std::deque<int>::const_reverse_iterator criter = evenNumbers.crbegin(); \
                criter != evenNumbers.crend(); ++criter)
    {
        std::cout << *criter << " ";
        if(*criter == 2)
        {
            //*criter = 0; //cannot assign criter is read-only
        }
    }
    std::cout << "\n";

    return 0;
}