#include <vector>
#include <string>
#include "printVectorContents.hpp"

int main()
{
    /* std::vector::data()
        Returns a direct pointer to the memory array used internally by the vector to store its owned elements.
     */

    std::vector <int> evenNumber{2,4,6,8,10};
    printVectorContents(evenNumber, "evenNumbers Before");

    int *ptrToFirstElement = evenNumber.data();
    std::cout << "First element in the vector is: " << *ptrToFirstElement << std::endl;

    auto iter = evenNumber.begin();
    std::cout << "Address of ptrToFirstElement is : " << ptrToFirstElement << std::endl;
    std::cout << "Address of iter : " << &iter << std::endl;

    *ptrToFirstElement++ =  10;
    *ptrToFirstElement =  8;
    ptrToFirstElement[3] = 2;
    printVectorContents(evenNumber, "evenNumbers After");

    std::vector<std::string> books{"c++","c", "js","python"};
    std::string *ptrToString = books.data();

    std::cout << "First book in the list is: " << ptrToString[2] << std::endl;


    return 0;
}