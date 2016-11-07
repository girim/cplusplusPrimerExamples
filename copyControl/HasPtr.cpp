/*
 * =====================================================================================
 *
 *       Filename:  HasPtr.cpp
 *
 *    Description:  :
 *
 *        Version:  1.0
 *        Created:  Wednesday 21 December 2016 10:19:02  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <iostream>

class HasPtr{
  public :
      HasPtr(const std::string &s = std::string("DEFAULT STRING")) : ps(new std::string(s)), i(0){}

      std::string getString()
      {
          return *ps;
      }

  private:
     std::string *ps;
     int i;
};

int main()
{
  HasPtr hasPtr_0;
  HasPtr hasPtr_1("Dragonstone");

  std::cout << "Value of string is: " << hasPtr_0.getString() << std::endl;
  std::cout << "Value of string is: " << hasPtr_1.getString() << std::endl;

  return 0;
}
