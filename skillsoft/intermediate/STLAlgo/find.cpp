#include <iostream>
#include <algorithm>
#include <list> //doubly linked list

int main()
{
    char letters[] = {'G', 'C', 'V', 'D'};
    std::list<std::string> colors{"red", "blue", "green", "yellow"};

    char *pointerToLetter = std::find(letters, (letters + sizeof(letters)/sizeof(char)), 'D');
    std::cout << "Found character is : " << *pointerToLetter << std::endl;

    std::list<std::string>::iterator foundColor = std::find(colors.begin(), colors.end(), "blue");
    std::cout << "Found color is: " << *foundColor << std::endl;

    while(foundColor != colors.end())
    {
        std::cout <<"Remaining colors in the list are: " << *foundColor++ << std::endl;
    }

    const char* rawStrings[] = {"js", "c++", "java", "c", "python"}; 
    const char** ptrToRawString = std::find(rawStrings, (rawStrings + (sizeof(rawStrings)/sizeof(char *))), "python");   
    std::cout << "pointer to raw string is: " << *ptrToRawString << std::endl;

    const char* ptr  = "someString";
    std::cout << "Full text: " << ptr << std::endl;
    std::cout << "First letter: " << *ptr << std::endl;

    return 0;
}