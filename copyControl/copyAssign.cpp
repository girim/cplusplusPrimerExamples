/*
 * =====================================================================================
 *
 *       Filename:  copyAssign.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Saturday 01 July 2017 11:23:04  IST
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
      Foo()
      {
          std::cout << "constructor: " << std::endl;
      };

      ~Foo()
      {
          std::cout << "destructor: " << std::endl;
      };

      Foo(const Foo& foo)
      {
          name_ = foo.name_;
          std::cout << "copy construtor: " << std::endl;
      }

      //Copy Assignment operator overloading
      Foo& operator=(const Foo& foo)
      {
          std::cout << "copy assignment funtion: " << std::endl;
          name_ =  foo.name_;
          return *this;
      }

  private:
      std::string name_;

};


int main()
{
    Foo foo1;
    Foo foo2 = foo1; //initialization
    Foo foo3 = foo2; //Initialization

    foo3 = foo1;//Assignment
}

