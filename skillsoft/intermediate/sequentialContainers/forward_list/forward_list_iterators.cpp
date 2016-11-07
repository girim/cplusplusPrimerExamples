#include <forward_list>
#include <iostream>

int main()
{
    std::forward_list<int> oddNumbers{1, 3, 7, 9};

    for(std::forward_list<int>::iterator iter = oddNumbers.begin();  \
            iter != oddNumbers.end(); ++iter)
    {
        std::cout << "element is : " << *iter << std::endl;
        if (*iter == 9)
            *iter = 5;
    }

    std::cout << "\n";
    for(std::forward_list<int>::const_iterator citer = oddNumbers.cbegin(); \
            citer != oddNumbers.cend(); ++citer)
    {
        std::cout << "element is : " << *citer << std::endl;
        /* if (*citer == 5)
            *citer = 7; */  //read-only   
    }

    return 0;
}