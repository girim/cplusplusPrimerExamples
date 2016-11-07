/*
 * =====================================================================================
 *
 *       Filename:  copyControlSynthesized.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Saturday 05 November 2016 10:35:59  IST
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

class Test
{
  public:
    Test(){};

    void setTestData(std::string text)
    {
        testData_ = text;
    }

    std::string getTestData()
    {
        return testData_;
    }

  private:
    std::string testData_;

};


int main()
{
    Test test;
    test.setTestData("testObject");

    Test copyOfTest(test);
    std::cout << "Name of the copyOfTest object is : "<< copyOfTest.getTestData() << std::endl;

}

