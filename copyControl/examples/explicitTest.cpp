/*
 * =====================================================================================
 *
 *       Filename:  explicitTest.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Saturday 01 July 2017 06:43:35  IST
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
      Foo() {};
      explicit Foo(std::string className) : className_(className) {};
      ~Foo() {};

      std::string getClassName()
      {
          return className_;
      }

  private:
      std::string className_;
};


int main()
{
    std::string className = "FOO";
    Foo foo ;//=  className;
    std::cout << "Class name for foo is : " << foo.getClassName() << std::endl;
    //foo = className;  //works only without explicit constructor
    std::cout << "Class name for foo is : " << foo.getClassName() << std::endl;
}
