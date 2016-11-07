#include <iostream>

class TestClass_1
{
	public: //compilter synthesizes default constructor & destructor 'TestClass_1()'
		int iVariable_;     //default initialized with garbage
		double dVariable_;	//default initialized with garbage
		std::string str_;   //default initialized with empty string
	private:
};

class TestClass_2
{
	public: //compilter synthesizes default constructor & destructor 'TestClass_1()'
		//Using in-class initializer to initialized data members
		int iVariable_ = 0;
		double dVariable_ = static_cast<double>(0.0);
		std::string str_ = "TestClass";
};

class SomeClass
{
public:
	SomeClass() = default; //explicitly as compiler to synthesize the default-constructor
	explicit SomeClass(int number, char ch) : number_(number), ch_(ch){};

private:
	int number_;
	char ch_;
};

class TestClass_3
{
public:
private:
	SomeClass sc;
	//SomeClass scc(1, 'a');  // cannot construct bcoz class does not have default constructor
};

class TestClass_4
{
public:
	TestClass_4(int &number, char & ch) 
	{
		SomeClass scc(number, ch);
	}

private:
	SomeClass sc;
	//SomeClass scc(1, 'a');  // cannot construct bcoz class does not have default constructor
};

std::ostream& operator<<(std::ostream& os, const TestClass_1& testClass)
{
	os << "{ iVariable: " << testClass.iVariable_ << \
		", dVariable: " << testClass.dVariable_ << ", str: " << testClass.str_ << " }" \
			<< std::endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, const TestClass_2& testClass)
{
	os << "{ iVariable: " << testClass.iVariable_ << \
		", dVariable: " << testClass.dVariable_ << ", str: " << testClass.str_ << " }" \
			<< std::endl;
	return os;
}

int main(int argc, char const *argv[])
{
	TestClass_1 testClass_1;
	std::cout << testClass_1;

	TestClass_2 testClass_2;
	std::cout << testClass_2;

	TestClass_3 testClass_3;

	return 0;
}