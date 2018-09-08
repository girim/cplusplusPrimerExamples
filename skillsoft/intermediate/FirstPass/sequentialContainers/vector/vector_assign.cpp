#include <vector>
#include <iostream>
#include <string>

template<typename T>
void printElements(const T& vec, std::string name)
{
    for(const auto& element : vec)
        std::cout << "Elements of : " << name << " is: " << element << std::endl;
}

int main()
{
    //std::vector::assign() 
    /* Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly. */
    std::vector<int> first;
    std::vector<int> second;
    std::vector<int> third;

    std::cout << "size of first [Before Assignment]: " << first.size() << std::endl;
    std::cout << "size of second[Before Assignment]: " << second.size() << std::endl;
    std::cout << "size of third [Before Assignment]: " << third.size() << std::endl;

    first.assign(4, 8);          //Using size and value
    second.assign({1, 3, 5, 7}); //Using initializer list
    third.assign(first.begin()+1, first.end());  //Using range 

    printElements(first, "first");
    printElements(second, "second");
    printElements(third, "third");

    std::cout << "size of first [After Assignment]: " << first.size() << std::endl;
    std::cout << "size of second[After Assignment]: " << second.size() << std::endl;
    std::cout << "size of third [After Assignment]: " << third.size() << std::endl;

    second.assign({2,4,6});
    printElements(second, "second2");
    std::cout << "size of second2[Before Assignment]: " << second.size() << std::endl;

    return 0;
}