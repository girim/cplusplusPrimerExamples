#include <iostream>
#include <algorithm>

void printElements(const int& number)
{
    std::cout << number * 4 << std::endl;
}

int main()
{
    std::vector<int> numbers{9,8,7,6};

    //using the named function
    std::for_each(numbers.begin(), numbers.end(), printElements);

    //using lambda expression
    std::for_each(numbers.begin(), numbers.end(), [](const int& number){
        std::cout << "Number is: " << number / 4 << std::endl;
    });
    
    return 0;
}