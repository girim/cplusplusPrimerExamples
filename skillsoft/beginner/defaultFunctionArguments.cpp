#include <iostream>

void testFunction(int number = 0, char letter = 'A', std::string text = "Hello")
{
    std::cout << "Arguements passed are: number: " << number << " letter: " << letter \
        << " text: " << text << std::endl; 
}

void testFunctionOne(int number, float digits = 1.02F, double price = 4.23323)
{
    std::cout << "Arguments passed are: number: " << number << " digits: " << digits \
        << " price: " << price << std::endl;
}

int main(int argc, char* argv[])
{
    testFunction();
    testFunction(10);
    testFunction(20, 'G');
    testFunction(30, 'S', "Hi");

    testFunctionOne(1);
    testFunctionOne(4, 2.02F);
    testFunctionOne(6, 3.5F, 233.232323);
    
    return 0;
}