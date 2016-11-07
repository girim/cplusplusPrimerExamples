#include <iostream>

//Function template to find the maximum of two objects
template<typename T>
T findMax(const T& left, const T& right)
{
	return (left > right) ? left : right; 
}


class Circle
{
public:
	Circle(std::string name = "", double radius = 0.0): radius_(radius), name_(name)
	{

	};
	~Circle(){};

	double getArea() const
	{
		return PI * radius_ * radius_;
	}

	std::string getCircleName()
	{
		return name_;
	}

private:
	std::string name_;
	double radius_;
	const double PI = 3.141592;
	double area_;
};
	 
//overloaded the '>' operator
bool operator>(const Circle& left, const Circle& right)
{
	return left.getArea() > right.getArea();
}

int main()
{
	int a = 10, b = 20;
	int *ptrA = &a;
	int *ptrB = &b;
	std::cout << "Max of (10, 10) is: " << findMax(10,10) << std::endl; 
	std::cout << "Max of (20, 30) is: " << findMax(*ptrA, *ptrB) << std::endl;
	std::cout << "Max of (40.493, 50.232) is: " << findMax(40.493, 50.232) << std::endl;
	std::cout << "Max of (A, D) is: " << findMax('A', 'D') << std::endl;

	Circle circleOne("Circle_A", 123);
	Circle circleTwo("Circle_B", 456);

	std::cout << "Big circle by area is(Circle_A, Circle_B): " << \
		findMax(circleOne, circleTwo).getCircleName() << std::endl; 
	return 0;
}

