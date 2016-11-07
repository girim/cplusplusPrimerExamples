#include <iostream>

class Circle
{
public:
	Circle(unsigned int radius = 0) : radius_(radius) {}
	~Circle(){};

 	unsigned int getRadius()
 	{
 		return radius_;
 	}

private:
	unsigned int radius_;
};

//overloading == operator
bool operator==(const Circle& lhs, const Circle& rhs)
{
	return (lhs.getRadius() == rhs.getRadius());
}

//overloading != operator
bool operator!=(const Circle& lhs, const Circle& rhs)
{
	return !(lhs == rhs);
}

//overloading < operator
bool operator<(const Circle& lhs, const Circle& rhs)
{
	return (lhs.getRadius() < rhs.getRadius());
}

int main()
{
	Circle circleOne(4);
	Circle circleTwo(5);
	Circle circleThree(4);

    if (circleOne < circleTwo)
    {
 		std::cout << "circleOne is smaller than circleTwo ...." << std::endl; 
    }

    if (circleOne == circleThree)
    {
		std::cout << "circleOne is same size as circleThree ...." << std::endl;
    }

    circleTwo = circleOne; //Assignment will be taken care by copy-assignment operator or move constuctor

    if (circleOne == circleTwo)
    {
    	std::cout << "circleOne is of same size as circleTwo now...." << std::endl;
    }


	return 0;
}