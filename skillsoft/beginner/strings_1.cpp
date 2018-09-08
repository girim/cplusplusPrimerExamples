#include <string>
#include <iostream>
#define EOL "\n"

int main(int argc, char const *argv[])
{
    std::string text("Hello C++");

    /* Normal iterator */
    for(std::string::iterator iter = text.begin(); iter != text.end(); ++iter)
    {
        std::cout << *iter <<  " "; 
    }
    std::cout << EOL;

    /* const iterator */
    for(std::string::const_iterator citer = text.cbegin(); citer != text.cend(); ++citer)
    {
        std::cout << *citer;
        //*citer = " ";
    }
    std::cout << EOL;

    /* reverse iterator */
    for(std::string::reverse_iterator riter =  text.rbegin(); riter != text.rend(); ++riter)
    {
        std::cout << *riter;
    }
    std::cout << EOL;

    /* const_reverse_iterator */
    for(std::string::const_reverse_iterator criter =  text.crbegin(); criter != text.crend(); ++criter)
    {
        std::cout << *criter;
        //*criter = "ds";  
    }
    std::cout << EOL;


    return 0;
}
