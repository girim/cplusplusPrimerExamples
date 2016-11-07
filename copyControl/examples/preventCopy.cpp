/*
 * =====================================================================================
 *
 *       Filename:  preventCopy.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Saturday 15 July 2017 12:31:35  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <iostream>

class NoCopy
{
  public:
      NoCopy() = default;
      ~NoCopy() = default;

      //'delete' indicates to the compiler that 'intentionaly not defining the these members'
      NoCopy(const NoCopy& nocopy) = delete;
      NoCopy& operator=(const NoCopy& nocopy) = delete;

      //We can make any function as 'deleted'
      void setName(std::string name) = delete;

      std::string getName()
      {
          return name_;
      }

  private:
      std::string name_;
};

int main()
{
   NoCopy originalObj;  // You cannot have another copy of this object, only one object instace is possible
   NoCopy anotherObj;
   std::cout << "Name of the object is: " << originalObj.setName("FOO") << std::endl;
   NoCopy copyOfObj = originalObj;
}
