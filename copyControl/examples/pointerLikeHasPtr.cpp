/*
 * =====================================================================================
 *
 *       Filename:  pointerLikeHasPtr.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Saturday 29 July 2017 06:26:39  IST
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
    public:
      //constructor
      HasPtr(const std::string &s =  std::string("DefaultString" )) :  ptrToString(new std::string(s)), number(0), useCount(new std::size_t(1))
      {
          std::cout << "constructor executed ...." << std::endl;
          std::cout <<"----> USE COUNT AT CONSTRUCTOR: " << *this->useCount << std::endl;
      }

      //copy constructor
      HasPtr(const HasPtr& hasPtr) : ptrToString(hasPtr.ptrToString), number(hasPtr.number), useCount(hasPtr.useCount)
      {
          std::cout << "copy constructor executed ...." << std::endl;
          ++*useCount;
          std::cout << "----> USE COUNT AT COPY CONTRUCTOR: " << *this->useCount << std::endl;
      }

      //copy-assignment operator
      HasPtr& operator=(const HasPtr& hasPtr)
      {
          std::cout << "copy-assignment operator executed ...." << std::endl;

          ++*(hasPtr.useCount);
          std::cout << "----> USE COUNT COPY-ASSIGNMENT RIGHT: " << *hasPtr.useCount << std::endl;

          if (--*(this->useCount) == 0)
          {
              delete ptrToString;
              delete useCount;
          }

          this->ptrToString = hasPtr.ptrToString;
          this->number = hasPtr.number;
          this->useCount = hasPtr.useCount;
          std::cout << "----> USE COUNT COPY-ASSIGNMENT LEFT : " << *this->useCount << std::endl;

          return *this;
      }

      ~HasPtr()
      {
          std::cout << "destructor executed ...." <<std::endl;
          std::cout << "----> USE COUNT AT DESTRUCTOR .... " << *this->useCount << std::endl;

          if (--*(this->useCount) == 0 )
          {
              std::cout << "Deleting the RESOURCE ...." << *this->useCount <<std::endl;
              delete ptrToString;
              delete useCount;
          }
      }

    private:
      std::string *ptrToString;
      int  number;
      std::size_t *useCount;
};


int main()
{
    HasPtr hasPtr_1;
    {
        HasPtr hasPtr_2(hasPtr_1);
        HasPtr hasPtr_3(hasPtr_2);
        hasPtr_1 = hasPtr_3;
    }
    hasPtr_1 = hasPtr_1;
    hasPtr_1 = hasPtr_1;
}
