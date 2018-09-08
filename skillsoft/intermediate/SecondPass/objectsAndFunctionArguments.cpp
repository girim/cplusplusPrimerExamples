#include <iostream>

class Person
{
    public:
        explicit Person(std::string, std::string);
        ~Person();

        std::string getFirstName() const;
        std::string getSecondName() const;
        std::string getFullName() const;

        void setFirstName(const std::string& firstName);
        void setSecondName(const std::string& secondName);

    private:
        std::string firstName_;
        std::string secondName_;
};

Person::Person(std::string firstName, std::string secondName): firstName_(firstName), secondName_(secondName){};

Person::~Person(){};

std::string Person::getFirstName() const
{
    return this->firstName_;
}

std::string Person::getSecondName() const
{
    return this->secondName_;
}

std::string Person::getFullName() const
{
    return this->firstName_ + " " + this->secondName_;
}

void Person::setFirstName(const std::string& firstName)
{
    this->firstName_ = firstName;
}

void Person::setSecondName(const std::string& secondName)
{
    this->secondName_ = secondName;
}

void testFunction(Person personByValue, Person* personByPointer, Person& personByReference)
{
    std::cout << "byValue: " << personByValue.getFullName() << "\n";
    std::cout << "byPointer: " << personByPointer->getFullName() << "\n";
    std::cout << "byReference: " << personByReference.getFullName() << "\n";

    personByValue.setFirstName("John");
    personByPointer->setFirstName("John");
    personByReference.setFirstName("John");
}

void testFunctionTakingConstants(const Person byValue, const Person* byPtr, const Person& byRef)
{
    std::cout << "byValue: " << byValue.getFullName() << "\n";
    std::cout << "byPtr: " << byPtr->getFullName() << "\n";
    std::cout << "byRef: " << byRef.getFullName() << "\n";
}

int main(int argc, char const *argv[])
{
    Person person1{"Steve", "Scott"};
    Person person2{"Peter", "Paine"};
    Person person3{"Tim", "Cook"};

    testFunction(person1, &person2, person3);

    std::cout << person1.getFullName() << "\n";
    std::cout << person2.getFullName() << "\n";
    std::cout << person3.getFullName() << "\n";

    testFunctionTakingConstants(person1, &person2, person3);
    
    return 0;
}
