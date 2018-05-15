#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Number of args passed is: " << argc << std::endl;
    for(int index = 0; index < argc; index++)
    {
        std::cout << "Arguments passed are: " << argv[index] << std::endl;
    }
    return 0;
}