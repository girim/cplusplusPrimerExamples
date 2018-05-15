#include <iostream>
#include <exception>

int main(int argc, char* argv[])
{
    try
    {
        int *ptr = new int;
        delete ptr;
    }
    catch (const std::bad_alloc&)
    {
        std::cout << "Bad allocation exception: " << std::endl;
        return 1;
    }

    std::string *s = new(std::nothrow)std::string();

    if(s == nullptr)
    {
        std::cout << "Problem with  memory allocation: " << std::endl;
        return 1;
    }
    delete(std::nothrow, s);

    char *msg  = new(std::nothrow) char[255];
    if(msg == nullptr)
    {
        std::cout << "Not able to allocate memory: " << std::endl;
    }
    delete [] (std::nothrow, msg);
    
    return 0;
}