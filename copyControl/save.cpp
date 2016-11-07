/*
 * =====================================================================================
 *
 *       Filename:  save.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Friday 30 December 2016 07:30:35  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <iostream>
#include <set>

void func(int &number);

void func(int &number)
{
  std::set<int*> numbers;
  numbers.insert(&number);

  for(auto num: numbers)
  {
      std::cout << "Numbers in the set are : " <<  *num << std::endl;
  }

}

int main()
{
  int numberFour = 4;
  func(numberFour);  //Pass by reference
  return 0;
}

