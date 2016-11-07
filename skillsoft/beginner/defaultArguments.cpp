#include <iostream>

/* Functions with default arguments */
void testFunction(int number = 0, char letter = '0', double fraction = 0.0)
{
    std::cout << "{ number = " << number << " ,letter = " << \
        letter << " ,double = " << fraction << " }" << std::endl;
}

/* Default arguements should always be at the end of non-default arguments */
void testFunction(char letter, int number = 100)
{
    std::cout << "{ letter = " << letter << " ,number = " << number << " }" << std::endl;
}

int main()
{
    testFunction();
    testFunction(5);
    testFunction(6, 'H');
    testFunction(4, 'G', 1.2);
    
    testFunction('F');
    testFunction('C', 4);

    return 0;
}