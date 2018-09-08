#include <iostream>
#include <string>
#define EOL "\n"


class Person
{
    public:
        explicit Person() : firstName_(""), secondName_(""){}
        explicit Person(std::string firstName, std::string secondName): firstName_(firstName), secondName_(secondName){}
        ~Person(){}
        std::string getFullName() const
        {
            return firstName_ + " " + secondName_;
        }

        void setFirstName(std::string firstName) 
        {
            this->firstName_ = firstName;
        }

        void setSecondName(std::string secondName)
        {
            this->secondName_ = secondName;
        }

    private:
        std::string firstName_;
        std::string secondName_;
};

void someFunction(Person byValue, Person *byPointer, Person &byReference)
{
    std::cout << "byValue: " << byValue.getFullName() << EOL;
    std::cout << "byPointer: " << byPointer->getFullName() << EOL;
    std::cout << "byReference: " << byReference.getFullName() << EOL;

    byValue.setFirstName("Akash");
    byPointer->setFirstName("Suhas");
    byReference.setFirstName("Ramesh");
}

int main(int argc, char const *argv[])
{
    Person rohit("Rohit", "Sharma");
    Person virat("Virat", "Kohli");
    Person suresh("Suresh", "Raina");

    someFunction(rohit, &virat, suresh);

    std::cout << "rohit: " << rohit.getFullName() << EOL;
    std::cout << "virat: " << virat.getFullName() << EOL;
    std::cout << "suresh: " << suresh.getFullName() << EOL;

    return 0;
}

