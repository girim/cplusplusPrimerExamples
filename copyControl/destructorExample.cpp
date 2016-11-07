#include <iostream>

class InnerTestClass
{
  public:
    InnerTestClass()
    {
        //Step 1.1 : Initialization of member function creates object
        std::cout <<"InnerTestClass constructor: " << std::endl;
    }

    ~InnerTestClass()
    {
        //Step 4: Nested object member is destroyed
        std::cout <<"InnerTestClass destructor: " << std::endl;
    }
};

class Test
{
  public:
    Test()
    {
      //Step 2: Body of the constuctor executes
      std::cout <<"Test constructor is called: " << std::endl;
    }

    ~Test()
    {
      //Step 3: Body of the destructor executes
      std::cout <<"Test destructor is called: " << std::endl;
    }

  private:
     //Step 1: First initialization of member happens
     InnerTestClass innerTestClass_;
};

int main()
{
   Test *dynamicallyAllocatedObj =  new Test;
   delete dynamicallyAllocatedObj;

   std::cout << "------------------------------------" << std::endl;
   Test testObject;
   return 0;
}
