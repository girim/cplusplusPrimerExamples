#include <iostream>

//Function template to find the maximum of two objects
template<typename T>
T findMax(const T& left, const T& right)
{
	return (left > right) ? left : right; 
}

//Example of usage of non-type template parameters
template<typename T, int max>
T findMin(T arr[], int size)
{
	int tmpMin = max;
	for(int index = 0; index < size; index++)
	{
		if(arr[index] < tmpMin)
		{
			tmpMin = arr[index]; 
		}
	}

	return tmpMin;
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

	int arrOne[] = {10,20,30,40};
	int sizeOfArrOne = sizeof(arrOne)/ sizeof(arrOne[0]);

	char arrTwo[] = {1,2,4};
	int sizeOfArrTwo =  sizeof(arrTwo) / sizeof(arrTwo[0]);

	std::cout << "Minimum value in arrOne is : " << findMin<int, 1000>(arrOne, sizeOfArrOne) << std::endl;
	std::cout << "Minimum value in arrTwo is : " << static_cast<int>(findMin<char, 256>(arrTwo, sizeOfArrTwo)) << std::endl;

	return 0;
}

