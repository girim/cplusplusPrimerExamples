#include <iostream>
#include "MyClass.hpp"

MyClass::MyClass(int data) : data_(data)
{
    std::cout <<"MyClass Contructor:" << std::endl; 
}

MyClass::~MyClass()
{
    std::cout <<"MyClass Destructor:" << std::endl;
}

int MyClass::getData()
{
    return data_;
}