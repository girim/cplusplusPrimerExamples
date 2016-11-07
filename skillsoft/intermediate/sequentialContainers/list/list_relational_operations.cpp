#include <list>
#include "../printContainerContents.hpp"

int main()
{
    std::list<int> firstList{10, 20, 30, 40};
    std::list<int> secondList{10, 20, 60, 70};
    std::list<int> thirdList{10, 20, 30, 40};

    if(firstList < secondList)
        std::cout << "firstList is \"Less than\"  secondList " << std::endl;

    if(secondList > firstList)
        std::cout << "secondList is \"Greater than \" firstList " << std::endl;

    if(firstList == thirdList)
        std::cout << "firstList is \"Equal to \" thirdList " << std::endl;
    
    if(firstList != secondList)
        std::cout << "firstList is \"Not Equal to \" secondList " << std::endl;
    
    if(firstList <= secondList)
        std::cout << "firstList is \"Less than or Equal \" to secondList " << std::endl;

    if (secondList >= firstList)
        std::cout << "secondList is  \"Greater than or Equal \" to firstList " << std::endl;
         
    return 0;
}