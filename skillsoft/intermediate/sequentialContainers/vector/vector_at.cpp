#include <vector>
#include <iostream>

template<typename T>
void printElements(const T& vec, std::string name)
{
    for(const auto& element : vec)
        std::cout << "Elements of : " << name << " is: " << element << std::endl;
}

int main()
{
    /* std::vector::at
       Returns a reference to the element at position n in the vector. throws out_of_range error
       if 'n' is out of range
     */
    std::vector<int> numbers{1, 2, 3, 4};
    printElements(numbers, "numbers");

    numbers.at(0) = 4;  //Since 'at' returns the reference we can use that reference to change the value
    printElements(numbers, "numbers");

    const std::vector<double> oddNumber{1, 3, 5, 7};
    //oddNumber.at(1) = 11;    //Returns reference to const so cannot assign

    try
    {
        numbers.at(5);
    }
    catch(std::out_of_range& error)
    {
        std::cout << "Index out of range " << error.what() << std::endl;
    }

    std::cout << "Element at 5th index: " << numbers[9] << std::endl;

    return 0;
}