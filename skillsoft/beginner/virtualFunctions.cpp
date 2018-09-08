#include <iostream>

class Employee
{
    public:
        explicit Employee(std::string firstName, std::string secondName, std::string dept) : \
                            firstName_(firstName), secondName_(secondName), department_(dept){}
        virtual ~Employee(){};

        std::string toString() const
        {
            return this->firstName_ + " " + this->secondName_ + " in " + this->department_;
        }

        virtual double getPaydayAmount()
        {
            return 0.0;
        }

    protected:
        std::string firstName_;
        std::string secondName_;
        std::string department_;
};

class Hourly : public Employee
{
    public:
        explicit Hourly(std::string fname, std::string lname, std::string dept, double payScale) : \
                    Employee(fname, lname, dept), payScale_(payScale), hoursWorked_(0.0){}
        virtual ~Hourly(){};
        virtual double getPaydayAmount() 
        {
            return payScale_ * hoursWorked_;
        }

        void inputHours(double hours)
        {
            this->hoursWorked_ = hours;
        }

    protected:
        double payScale_;
        double hoursWorked_;

};

class Salary : public Employee
{
    public:
        explicit Salary(std::string fname, std::string lname, std::string dept, double salary) : \
                            Employee(fname, lname, dept), salary_(salary){};

        virtual ~Salary(){}
        double getPaydayAmount()
        {
            return salary_ / 26;
        }
    private:
        double salary_;
};

int main(int argc, char const *argv[])
{
    Employee employee("Amit", "sharma", "R&D");
    Hourly hourlyEmployee("Ratan", "Singh", "Manager", 29);
    hourlyEmployee.inputHours(8);

    Salary salarizedEmp("Steve", "chen","Research", 56000);

    /* std::cout << "Salary for employee: " << employee.getPaydayAmount() << std::endl;
    std::cout << "Salary for hourlyEmployee: " << hourlyEmployee.getPaydayAmount() << std::endl;
    std::cout << "Salary for salarizedEmp: " << salarizedEmp.getPaydayAmount() << std::endl; */

    Employee *pts[3] = {&employee, &hourlyEmployee, &salarizedEmp};


    for(auto ptr: pts)
    {
        std::cout << "PayDayAmount: " << ptr->getPaydayAmount() << " for " << ptr->toString() << std::endl;
    }

    return 0;
}
