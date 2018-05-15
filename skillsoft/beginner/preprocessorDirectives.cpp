#include <iostream>

#define ENABLE
#define DEBUG_LEVEL 0
#define ISTRUE TRUE

#ifdef ENABLE
void debugLog()
{
    std::cout << "This is debug log with debug level: " << DEBUG_LEVEL << std::endl;
}
#endif // DEBUG

#define SQUARE(x) (x * x)

#if (ISTRUE == TRUE)
    void doSomething()
    {
        for(int index = 0; index < 4; index++)
        {
            std::cout <<"Index " << index << std::endl;
        }
    }
#elif
    int doSomething()
    {
    }
#endif // DEBUG

int main()
{
    int square = SQUARE(4);
    std::cout << "Square of 4 is : " << square << std::endl;

    std::cout << "FileName: " << __FILE__ << std::endl;
    std::cout << "Date: " << __DATE__ << std::endl;
    
    return 0;
}