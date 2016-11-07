/*
 * =====================================================================================
 *
 *       Filename:  valueLikeHasPtr.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Friday 28 July 2017 12:57:27  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>

class HasPtr
{
  public :
      //constructor
      HasPtr(const std::string &refToDefaultString = std::string("DefaultString")) : ptrToString(new std::string(refToDefaultString)), number(0)
      {
          std::cout << "----> contructor executed .... " << std::endl;
      };

      //copy constructor
      HasPtr(const HasPtr& hasPtr) : ptrToString(new std::string(*(hasPtr.ptrToString))), number(hasPtr.number)
      {
          std::cout << "----> copy constructor ...." << std::endl;
      };

      //copy-assignment operator
      HasPtr& operator=(const HasPtr& hasPtr)
      {
          std::cout << "----> copy assignment operator ...." << std::endl;
          //Copy the  resource first
          std::string *ptrToCopiedObj = new std::string(*(hasPtr.ptrToString));

          //delete the existing resource
          delete ptrToString;

          //assign the new resource to the existing ptr
          ptrToString =  ptrToCopiedObj;
          number = hasPtr.number;

          //return reference to this object
          return *this;
      }

      //destructor
      ~HasPtr()
      {
          std::cout << "----> destructor executed ...." << std::endl;
          delete ptrToString;
      };


      std::string getName()
      {
          return *ptrToString;
      }

  private:
      std::string *ptrToString;
      int number;
};

int main()
{
      HasPtr hasPtr_1;
      std::cout << "hasPtr_1 string is : " << hasPtr_1.getName() << std::endl;

      HasPtr hasPtr_2(hasPtr_1);
      std::cout << "hasPtr_2 string is : " << hasPtr_2.getName() << std::endl;

      HasPtr hasPtr_3("DragonStone");
      std::cout  << "hasPtr_3 string is : " << hasPtr_3.getName() << std::endl;

      hasPtr_1 = hasPtr_3;
      std::cout  << "hasPtr_1 string is : " << hasPtr_1.getName() << std::endl;

      return 0;
}
