#include <iostream>

class B
{
	public:
		B()=default;
		~B()=delete; //destructor is deleted
	private:
		//~B();
};

class A
{
	public:
		A() = default;
		~A() = default;
	private:
		B b;
};

class C
{
	public:
		C()=default;
		~C()=default;
		C(const C&)=delete;  //deleted copy-constructor

	private:
};

class D
{
	public:
		D() = default;
		~D() = default;
		D(const D&) = default; //will be synthesized as deleted
	private:
		C c;
};

class E
{
	public:
		E() = default;
		~E() = default;
		E& operator=(const E&) =default;
	private:
		const int id_;// = 1;
		int var = 10;
		int &ref_;// = var;
};

class F
{
	public:
		F() = default;
		~F() = default;
		F& operator=(const F& f) = default;

	private:
		E e;
};

int main(int argc, char const *argv[])
{
	//A a{}; //Both synthesized constructor and destructor are deleted
	//A a1(a); //copy-constructor will be synthesized as deleted bcoz B's destructor is deleted

	//D d{};
	//D d1{d};

	F f{};
	return 0;
}