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
#include <vector>
#include <algorithm>

class HasPtr
{
  public :
      friend void swap(HasPtr &lhs, HasPtr &rhs);

      //constructor
      HasPtr(const std::string &refToDefaultString = std::string("DefaultString")) : ptrToString(new std::string(refToDefaultString)), number(0)
      {
          std::cout << "----> contructor executed .... " << std::endl;
      };

      //copy constructor
      HasPtr(const HasPtr& hasPtr) : ptrToString(new std::string(*(hasPtr.ptrToString))), number(hasPtr.number)
      {
          std::cout << "----> copy constructor ...." << *ptrToString << std::endl;
      };

      //copy-assignment operator using COPY-AND-SWAP technique
      HasPtr& operator=(HasPtr hasPtr)
      {
          std::cout << "----> copy assignment operator ...." << *ptrToString << std::endl;
          swap(*this, hasPtr);
          //return reference to this object
          return *this;
      }

      //destructor
      ~HasPtr()
      {
          std::cout << "----> destructor executed ...." <<*ptrToString << std::endl;
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

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
   using std::swap;
   std::cout << "HasPtr::swap() function called... " << std::endl;
   swap(lhs.ptrToString, rhs.ptrToString);
   swap(lhs.number, rhs.number);
}

class Foo{
  public:
    friend void swap(Foo &lhs, Foo &rhs);

    Foo(int id, HasPtr &hasPtr): id_(id), hasPtr_(hasPtr)
    {
        std::cout << "Foo contructor called: ..." << std::endl;
    }
    ~Foo(){}

  int getId()
  {
      return id_;
  }
  private:
    int id_;
    HasPtr hasPtr_;
};

inline void swap(Foo &lhs, Foo &rhs)
{
   using std::swap;
   std::cout <<"Foo::swap() function called ... " << std::endl;
   swap(lhs.hasPtr_, rhs.hasPtr_);
   swap(lhs.id_, rhs.id_);
}

int main()
{
      HasPtr hasPtr_1("hasPtr_1");
      HasPtr hasPtr_2("hasPtr_2");
      HasPtr hasPtr_3("hasPtr_3");
      HasPtr hasPtr_4("hasPtr_4");
      HasPtr hasPtr_5("hasPtr_5");
      HasPtr hasPtr_6("hasPtr_6");
      HasPtr hasPtr_7("hasPtr_7");
      HasPtr hasPtr_8("hasPtr_8");
      HasPtr hasPtr_9("hasPtr_9");
      HasPtr hasPtr_10("hasPtr_10");
      HasPtr hasPtr_11("hasPtr_11");
      HasPtr hasPtr_12("hasPtr_12");
      HasPtr hasPtr_13("hasPtr_13");
      HasPtr hasPtr_14("hasPtr_14");
      HasPtr hasPtr_15("hasPtr_15");
      HasPtr hasPtr_16("hasPtr_16");
      HasPtr hasPtr_17("hasPtr_17");
      HasPtr hasPtr_18("hasPtr_18");
      HasPtr hasPtr_19("hasPtr_19");
      HasPtr hasPtr_20("hasPtr_20");
      HasPtr hasPtr_21("hasPtr_21");

      Foo foo_1(1111, hasPtr_1);
      Foo foo_2(3333, hasPtr_2);
      Foo foo_3(2222, hasPtr_3);
      Foo foo_4(4444, hasPtr_4);
      Foo foo_5(6666, hasPtr_5);
      Foo foo_6(5555, hasPtr_6);
      Foo foo_7(9999, hasPtr_7);
      Foo foo_8(8888, hasPtr_8);
      Foo foo_9(7, hasPtr_9);
      Foo foo_10(77, hasPtr_10);
      Foo foo_11(777, hasPtr_11);
      Foo foo_12(7777, hasPtr_12);
      Foo foo_13(1, hasPtr_13);
      Foo foo_14(27, hasPtr_14);
      Foo foo_15(3, hasPtr_15);
      Foo foo_16(757, hasPtr_16);
      Foo foo_17(7877, hasPtr_17);
      Foo foo_18(7787, hasPtr_18);
      Foo foo_19(7778, hasPtr_19);
      Foo foo_20(7797, hasPtr_20);
      Foo foo_21(7747, hasPtr_21);
      //After adding more items to vector customized swap methods were called

      std::vector<Foo> foolist = {foo_1, foo_2, foo_3, foo_4, foo_5, foo_6, foo_7, foo_8, foo_9, \
                                  foo_10, foo_11, foo_12, foo_13, foo_14, foo_15, foo_16, foo_17, foo_18, foo_19, foo_20, foo_21};

      std::cout <<"Sorting started ...." << std::endl;
      std::sort(foolist.begin(), foolist.end(),[](Foo &foo1, Foo &foo2){
              return (foo1.getId() < foo2.getId());
          });
      return 0;
}
