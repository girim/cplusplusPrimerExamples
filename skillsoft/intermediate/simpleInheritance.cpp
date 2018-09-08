#include <iostream>

class Animal
{
    public:
        Animal(unsigned arms, unsigned legs, unsigned age): arms_(arms), legs_(legs), age_(age){};
        ~Animal(){};

        void eat()
        {
            std::cout << "Eating ...." << "\n";
        }

        void sleep()
        {
            std::cout << "Sleeping...." << "\n";
        }

        void drink()
        {
            std::cout << "Drinking...." << "\n";
        }

    protected:
        unsigned arms_;
        unsigned legs_;
        unsigned age_;
};


class Dog : public Animal
{
    public:
        Dog(unsigned arms, unsigned legs, unsigned age) : Animal(arms, legs, age){}
        ~Dog(){};

        unsigned getArms() const { return this->arms_;};
        unsigned getLegs() const { return this->legs_;};
        unsigned getAge() const { return this->age_;};
};

int main(int argc, char const *argv[])
{
    Dog dog{2, 4, 10};
    dog.drink();
    dog.sleep();
    dog.eat();

    std::cout << dog.getArms() << "\n";
    
    return 0;
}
