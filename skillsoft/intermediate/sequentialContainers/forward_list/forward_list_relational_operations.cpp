#include  <forward_list>
#include "../printContainerContents.hpp"
#include "../Plane.hpp"

int main()
{
    std::forward_list<int> first{20, 30, 40};
    std::forward_list<int> second{20, 30, 40};
    std::forward_list<int> third{20, 4, 1};

    if(first == second)
        std::cout << "first is Equal to second " << std::endl;

    if(first != third)
        std::cout << "first is Not Equal to third " << std::endl;
    
    if(third < first)
        std::cout << "third is less than first " << std::endl;
    
    if(first > third)
        std::cout << "first is greater than third " << std::endl;
    
    if(third <= first)
        std::cout << "third is less than or Equal first " << std::endl;

    if(first >= third)
        std::cout << "first is greater than or Equal first " << std::endl;

    return 0;
}