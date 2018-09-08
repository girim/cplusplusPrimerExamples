#include <iostream>
#include <vector>

int main()
{
    std::vector<int> decimals{0,1,2,3,4,5,6,7,8,9};

    //end(), begin()
    for(std::vector<int>::iterator iter = decimals.begin(); iter != decimals.end(); ++iter)
    {
        std::cout << *iter << " ";
        if(*iter == 0)
            *iter = 999;   //can modify as the iter is readable/writable
    }
    std::cout << "\n";
    
    //rbegin(), rend()
    for(std::vector<int>::reverse_iterator riter = decimals.rbegin(); \
                riter != decimals.rend(); ++riter)
    {
        std::cout << *riter << " ";
        if (*riter == 999)
            *riter = 0;
    }
    std::cout << "\n";

    //cend(), cbegin()
    for(std::vector<int>::const_iterator iter = decimals.cbegin(); \
                iter != decimals.cend(); ++iter)
    {
        std::cout << *iter << " ";
        //*iter = 0;   //cannot modify since iter is read-only
    }
    std::cout << "\n";

    for(std::vector<int>::const_reverse_iterator criter = decimals.crbegin(); \
                criter != decimals.crend(); ++criter)
    {
        std::cout << *criter << " ";
        //*criter = 0; //cannot modify since criter is read-only
    }
    std::cout << "\n";

    return 0;
}