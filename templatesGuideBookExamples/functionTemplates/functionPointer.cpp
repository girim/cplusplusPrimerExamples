#include <iostream>

void testFunction_1()
{
    std::cout << "testFunction_1 called ...." << std::endl;
}

void testFunction_2(int (*ptr)(int,int), std::string msg)
{
    ptr(4, 5);
}

int addTwoIntegers(int x, int y)
{
    std::cout << "addTwoIntegers called ...." << x + y << std::endl;
    return x + y;
}

int main(int argc, char* argv[])
{
    void(*fp)(void) = testFunction_1;
    fp();

    int (*ptrToAddTwoIntegers)(int, int) = addTwoIntegers;
    std::cout << "Result: " << ptrToAddTwoIntegers(90, 10) << "\n";
    testFunction_2(addTwoIntegers, "Message");

    return 0;
}