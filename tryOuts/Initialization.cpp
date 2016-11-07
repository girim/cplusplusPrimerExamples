#include "Initialization.hpp"

Test::Test(int data) : data_(data) {};

Test::~Test(){};

/* Test::Test(Test& test)
{
    std::cout <<"{copy constructor}" << std::endl;
    this->data_ = test.data_;
} */

int Test::getData() const
{
    return data_;
}

int main()
{
    Test t1;        // Default Initialization
    Test t2{};      // List Initialization
    Test t3{4};     // List Initialization
    Test t4 = {8};  // Copy Initialization
    Test t5 = 16;   // Copy Initialization
    Test t6(32);    // Direct Initialization
    Test t7(t2);    // Copy Initialization

    std::cout << t1;
    std::cout << t2;
    std::cout << t3;
    std::cout << t4;
    std::cout << t5;
    std::cout << t6;
    std::cout << t7;

    return 0;
}
