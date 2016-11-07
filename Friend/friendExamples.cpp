#include <iostream>
class Foo;

class Bar
{
    public:
        Bar(int data = 0): data_(data){};
        ~Bar(){};
        void someFunc();
    private:
        int data_;
};

class Foo
{
    public:
        Foo(int variable = 0) : variable_(variable) { }
        ~Foo()= default;
        friend int getVariable(const Foo& foo);/* Friend declaration */
        friend void Bar::someFunc();
    private:
        int variable_;
};

void Bar::someFunc()
{
    Foo foo;
    std::cout << foo.variable_ << std::endl;
}
int getVariable(const Foo& foo)
{
    return foo.variable_;
}

int main()
{
    Foo foo1{};
    Foo foo2{4};
    std::cout << "Value is: " << getVariable(foo1) << std::endl;
    std::cout << "Value is: " << getVariable(foo2) << std::endl;

    Bar bar{};
    bar.someFunc();

    return 0;
}