#include <iostream>

namespace TEST_NAMESPACE
{
    void greetings()
    {
        std::cout << "Welcome to C++ " << std::endl;
    }

    void leaving()
    {
        std::cout << "Good Bye....!" << std::endl;
    }
}

using namespace TEST_NAMESPACE;
namespace TN = TEST_NAMESPACE;   //creating alias

int main(int argc, char const *argv[])
{
    //TEST_NAMESPACE::greetings();
    //TEST_NAMESPACE::leaving();

    greetings();
    leaving();

    TN::greetings();
    TN::leaving();

    return 0;
}
