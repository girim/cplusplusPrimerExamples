#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    double numbers[] = {9.9, 6.6, 3.3, 4.4, 4.4, 1.0, 2.2, 2.2, 5.5};
    std::string text{"I am getting too late...."};

    //without using predicate
    auto iter_1 = std::adjacent_find(std::begin(numbers), std::end(numbers));
    std::cout << "Found first occurences of numbers: " << *iter_1 << std::endl;

    //Using predicate to find adjacents
    auto iter_2 = std::adjacent_find(std::begin(numbers), std::end(numbers), \
                [](const double& prev, const double& cur){
                        //std::cout << "prev: " << prev << " cur: " << cur << std::endl;
                        return ((prev < 4 && cur < 4) && (prev == cur));
                });
            
    std::cout << "Found occurence is: " << *iter_2 << std::endl;

    //mactches 'tt' in word 'getting' of string text 
    auto iter_3 =  std::adjacent_find(text.begin(), text.end());
    std::cout << "Found occurence is : " << *iter_3 << std::endl;

    return 0;
}