#ifndef __FOO_HPP__
#define __FOO_HPP__

#include <iostream>
#include "Bar.hpp"

class Foo
{
    public:
        Foo(int data = 0);
        ~Foo();
        int getData() const;

        /* Friend Declarations */
        friend void someFunc();  //Non-Member function can be a friend
        friend std::ostream& operator<<(std::ostream& os, const Foo &foo); //Non-memeber funtion
        friend void Bar::combineDataFromFooAndBar(Foo &foo); //Member function of the another class can be a friend
        friend Bar::Bar(double data), Bar::~Bar(); //Constructor/Destructor of another class can be friends

        /* can define the non-member function and make it as friend at the same time */
        friend void NonMemberFunction()
        {
            std::cout << "NonMemberFunction defined inline...." << std::endl;
        }

    private:
        int data_;
};

#endif //__FOO_HPP__