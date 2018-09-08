#include <vector>
#include "point.hpp"

/* Vector uses 'Random Access Iterators' */

int main(int argc, char const *argv[])
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};

    std::cout << " --- iterator [begin, end) --- " << std::endl;
    for(std::vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); ++iter)
    {
        std::cout << "Element is : " << *iter << std::endl;
        if(*iter == 5){
            *iter = 0;
        }
    }

    std::cout << " --- const_iterator [cbegin, cend) --- " << std::endl;
    for(std::vector<int>::const_iterator citer = numbers.cbegin(); citer != numbers.cend(); citer++)
    {
        std::cout << "Element is : " << *citer << std::endl;
        if(*citer == 0){
            //*citer = 5;
        }
    }

    std::cout << " --- reverse_iterator [rbegin, rend) --- " << std::endl;
    for(std::vector<int>::reverse_iterator riter = numbers.rbegin(); riter != numbers.rend(); riter++)
    {
        std::cout << "Element is : " << *riter << std::endl;
        if(*riter == 0){
            *riter = 8;
        }
    }

    std::cout << " --- const_reverse_iterator [crbegin, crend) --- " << std::endl;
    for(std::vector<int>::const_reverse_iterator criter = numbers.crbegin(); criter != numbers.crend(); criter++)
    {
        std::cout << "Element is : " << *criter << std::endl;
        if(*criter == 8){
            //*criter = 10;
        }
    }

    return 0;
}

