#include <list>
#include "../printContainerContents.hpp"

int main()
{
    std::list<std::string> teams{"DD", "RR", "MI", "SRH"};

    /* [begin, end) */
    for(std::list<std::string>::iterator iter  = teams.begin(); iter != teams.end(); ++iter)
    {
        if(*iter == "MI")
            *iter = "KXIP";
        std::cout << *iter << " ";
    }
    std::cout << "\n";

    /* [cbegin, cend) */
    for(std::list<std::string>::const_iterator citer = teams.cbegin(); citer != teams.cend(); ++citer)
    {
        if(*citer == "KXIP")
        {
            //*citer = "MI"    //cannot change read-only
        }
        std::cout << *citer << " ";
    }
    std::cout << "\n";

    /* [rbegin, rend) */
    for(std::list<std::string>::reverse_iterator riter = teams.rbegin(); riter != teams.rend(); ++riter)
    {
        if(*riter == "DD")
            *riter = "KKR";
        std::cout << *riter << " ";
    }
    std::cout << "\n";

    /* [crbegin, crend) */
    for(std::list<std::string>::const_reverse_iterator criter = teams.crbegin(); \
            criter != teams.crend(); ++criter)
    {
        if(*criter == "KKR")
        {
            //*criter = "RCB";  //cannot change read-only
        }
        std::cout << *criter << " ";
    }
    std::cout << "\n";

    return 0;
}