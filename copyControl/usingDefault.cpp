/*
 * =====================================================================================
 *
 *       Filename:  usingDefault.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Monday 10 July 2017 11:19:52  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <iostream>

class Foo
{
    public:
        Foo() = default;
        Foo(const Foo& foo) = default;
        Foo& operator=(const Foo& foo) = default;
        ~Foo() = default;


        std::string getName()
        {
            return name_;
        }

        void setName(std::string name)
        {
            name_ = name;
        }

    private:
      std::string name_;

};

int main()
{
    Foo foo1;
    foo1.setName("FOO-1");

    Foo foo2{foo1};   //List initialization
    Foo foo3(foo2);   //Direct initialization
    Foo foo4 = foo3;  //copy initialization

    std::cout << foo1.getName() << std::endl;
    std::cout << foo2.getName() << std::endl;
    std::cout << foo3.getName() << std::endl;
    std::cout << foo4.getName() << std::endl;
}
