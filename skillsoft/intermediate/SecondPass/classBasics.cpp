#include <iostream>

class Base
{
    public:
        unsigned publicMember_ = 10;

    private:
        unsigned privateMember_ = 20;

    protected:
        unsigned protectedMember_ = 30;
};

class Derived : public Base
{
    public:
        void canAcessPublicMember()
        {
            std::cout << "can access public member: " << publicMember_ << "\n";
        }

        void canAccessPrivateMember()
        {
            //std::cout << "can access private member: " << privateMember_ << "\n";
        }

        void canAccessProtectedMember()
        {
            std::cout << "can access protected member: " << protectedMember_ << "\n";
        }
};

int main(int argc, char const *argv[])
{
    Derived d1;
    Base b1;
    std::cout << "Can access public member outside class: " << b1.publicMember_ << "\n";
    //std::cout << "Can not access  private member outside class: " << b1.privateMember_ << "\n";
    //std::cout << "Can not access  protected member outside class: " << b1.protectedMember_ << "\n";

    std::cout << "child class can access public member of parent class: " << d1.publicMember_ << "\n";
    //std::cout << "child class can not access protected member of parent class: " << d1.protectedMember_ << "\n";
    //std::cout << "child class can not access private member of parent class: " << d1.privateMember_ << "\n";

    d1.canAcessPublicMember();
    d1.canAccessProtectedMember();
    d1.canAccessPrivateMember();

    return 0;
}
