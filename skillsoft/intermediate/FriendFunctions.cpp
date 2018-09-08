#include <iostream>

class Foo
{
    public:
        explicit Foo() : privateVar_(0){};
        ~Foo(){};
    
        unsigned getPrivateVar() const { return this->privateVar_;}

        /* friend declaration */
        friend void someFunction(Foo &foo);

    private:
        unsigned privateVar_;
};

void someFunction(Foo &foo)
{
    foo.privateVar_++;
}

int main(int argc, char const *argv[])
{
    Foo foo{};
    std::cout << "Value: " << foo.getPrivateVar() << "\n";

    someFunction(foo);
    someFunction(foo);

    std::cout << "Value: " << foo.getPrivateVar() << "\n";
    
    return 0;
}
