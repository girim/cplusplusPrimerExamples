#include <iostream>

class Employee
{
    public:
        explicit Employee(std::string , std::string, std::string);
        virtual ~Employee();

        virtual double getPaydayAmount() 
        {
            return 0.0;
        }

    private:
        std::string firstName_;
        std::string secondName_;
        std::string department_;
};

Employee::Employee(std::string firstName, std::string secondName, std::string department) : \
        firstName_(firstName), secondName_(secondName), department_(department){};

Employee::~Employee(){};


class HourlyEmployee : public Employee
{
    public:
        explicit HourlyEmployee(std::string, std::string, std::string, double scale);
        virtual ~HourlyEmployee();

        void inputHours(unsigned hours)
        {
            this->hours_ = hours;
        }

        virtual double getPaydayAmount()
        {
            return (scale_ /hours_);
        }

    private:
        double scale_;
        unsigned hours_ = 1;
};

HourlyEmployee::HourlyEmployee(std::string fname, std::string lname, std::string dept, double scale) : \
        Employee(fname, lname, dept), scale_(scale){};
HourlyEmployee::~HourlyEmployee(){};

class Salarized: public Employee
{
    public:
        explicit Salarized(std::string fname, std::string lname , std::string dept, double salary) : Employee(fname, lname, dept), salary_(salary){};
        virtual ~Salarized(){};

        virtual double getPaydayAmount()
        {
            return salary_/26;
        };

    private:
        double salary_;
};

int main(int argc, char const *argv[])
{
    Employee employee("Steve", "Scot", "Edu");
    HourlyEmployee hourlyEmployee("Peter", "Parker", "R&D", 130000);
    Salarized salarize("Tom", "Cook", "Sales", 24000);

    Employee* employes[] = {&employee, &hourlyEmployee, &salarize};

    for(auto ptr : employes)
    {
        std::cout << "Pay day amount: " << ptr->getPaydayAmount() << "\n";
    }

    return 0;
}


