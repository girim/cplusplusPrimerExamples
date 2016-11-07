#include <iostream>

//global variable
double gVariable; //default initialized global variable

void localFunction()
{
	int var;  //Default initialized, would store some arbitary value
	std::cout << "Value of var : " << var << std::endl;
}

class TestClass
{
	public:
		/*CIL: Constructor Initializer List*/
		//explicit TestClass(int id = 1) : id_(id) {};
		//explicit TestClass(int id, char ch) : id_(id), ch_(ch) {};
	    TestClass(int id = 1) : id_(id) {};
		TestClass(int id, char ch) : id_(id), ch_(ch) {};

		~TestClass() = default;

	const int getId() const
	{
		return id_;
	}

	const char getCh() const
	{
		return ch_;
	}

	private:
		int id_;
		char ch_;
};

std::ostream& operator<<(std::ostream& os, const TestClass& testClass)
{
	os << "{TestClass, Id: " << testClass.getId() << "}";
}

int main(int argc, char const *argv[])
{
	/*1. List intialization*/
	int a = 1;
	int b{4};       //List Initialization
	int c = {5};    //List Initialization
	int d(6);
	int e = (7);

	std::cout << "a: " << a << " b: " << b << " c: "  \
		<< c << " d: " << d << " e: " << e << std::endl;

	/*2. Default initialization*/
	float someVar;
	std::cout <<"Value of someVar: " << someVar << std::endl;
	localFunction();
	std::cout <<"Default initialized gVariable: " << gVariable << std::endl;
	TestClass testClass_1;  //default initialized testClass
 	std::cout << testClass_1 << std::endl;

	/*3. Direct initialization: Using contructor of the class to initialize*/
 	TestClass testClass_2(4, 'G');
 	std::cout << testClass_2 << std::endl;

	/*4. Copy Initialization: Using = to initialize the variables*/
 	TestClass testClass_3 = 5;
 	std::cout << testClass_3 << std::endl;
 	/*IF THE CLASS HAS SINGLE PARAMTER CONSTUCTOR we can use both direct & copy for
 		initiailization */

 	TestClass testClass_4(testClass_2); //Using synthesized copy constructor
 	std::cout << testClass_4 << std::endl;
	/*5. Value Initialization*/

	return 0;
}