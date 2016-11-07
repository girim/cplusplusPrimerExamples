/*
 * =====================================================================================
 *
 *       Filename:  copyControl.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Saturday 01 July 2017 01:50:03  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <iostream>

class Test
{
  public :
  Test()
  {
      std::cout << "Test constructor: " << std::endl;
  }

  ~Test()
  {
      std::cout << "Test destructor: " << std::endl;
  }

  //copy constructor
  Test(const Test& test)
  {
      std::cout << "Test copy constructor: " << std::endl;
      testData_=  test.testData_;
  }


  private:
     int testData_ = 0;

};

Test someFunction(Test test)
{
    std::cout << "Inside someFunction: " << std::endl;
    return test;
}

int main()
{
    Test test1;
    Test test2(test1);     //direct initialization which uses copyConstructor
    Test test3  = test2;   //copy initialization
    /*Test test4{test3};     //List initialization
    Test test5 = {test4};  //List initialization

    std::cout << "Before calling someFunction: " << std::endl;
    Test test6 = someFunction(test5); //copy initialization

    Test tests[2] = {test1, test2}; //copy initialization*/

    return 0;
}


