/*
 * =====================================================================================
 *
 *       Filename:  refAsMember.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Saturday 15 July 2017 05:21:22  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <iostream>

int main()
{
  int a =10;
  int b = 20;
  int &refToA = a;


  std::cout <<"Address of a      : " << &a << std::endl;
  std::cout <<"Address of refToA : " << &refToA << std::endl;
  refToA = b;
  std::cout <<"Address of refToA : " << &refToA << std::endl;
  std::cout <<"Address of b      : " << &b << std::endl;

}
