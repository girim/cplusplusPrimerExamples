#include <iostream>

int main()
{
    int number = 0;
    std::string textMsg  = "Thank You \n Bye";

    while(number != 22) 
    {
        std::cout << "\nPlease enter a number: ";
        std::cin >> number;

        if(number != 22) 
        {
            std::cerr << "You entered: " << number;
        }
        std::cout << std::endl << std::endl;
    }
    std::cout << textMsg << std::endl;

    return 0;
}