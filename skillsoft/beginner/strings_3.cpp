#include <iostream>
#include <string>
#define EOL "\n"

int main(int argc, char const *argv[])
{
    /* Element access */
    /* 1. using [] operator */
    std::string str("Hello");
    std::cout << "first character is : " << str[0] << EOL;
    std::cout << "first character is : " << str[4] << EOL;

    /* 2. using 'at' function */
    std::cout << "character at 1st position: " << str.at(1) << EOL;
    
    
    try
    {
        str.at(6);  // 'at' throws out_of_range exception
    }
    catch(const std::out_of_range& e)
    {
        std::cout << "out_of_range exception ...." << EOL;
        std::cerr << e.what() << '\n';
    }
    str.at(0) = 'h';
    
    /* 3. front --> returns the reference to the first character of the string */
    std::cout << "first character of string str is: " << str.front() << EOL;

    /* 4. back --> returns the reference to the last character of the string */
    std::cout << "last character of string str is: " << str.back() << EOL;

    return 0;
}
