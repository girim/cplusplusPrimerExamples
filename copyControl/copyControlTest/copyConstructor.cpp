#include <iostream>

class SquareShape
{
	public:
		explicit SquareShape(double sideA = 1, double sideB = 1) :
			sideA_(sideA), sideB_(sideB)
			{
				std::cout << "square constructor " << std::endl;
			}
		/*copy constructor*/
		SquareShape(const SquareShape& square)
		{
			std::cout << "square copy-construtor" << std::endl;
			this->sideA_ = square.sideA_;
			this->sideB_ = square.sideB_;
		}

		/*copy-assignment operator*/
		SquareShape& operator=(const SquareShape& square)
		{
			std::cout << "square copy-assignment" << std::endl;
			this->sideA_ = square.sideA_;
			this->sideB_ = square.sideB_;

			return *this;
		}

		double getArea() const { return sideA_ * sideB_;}
		double getSideA() const { return sideA_; }
		double getSideB() const { return sideB_; }

	private:
		double sideA_;
		double sideB_;
};

std::ostream& operator<<(std::ostream& os, const SquareShape& square)
{
	os << "{ sideA: " << square.getSideA() << \
		" sideB: " << square.getSideB() << \
			" Area: " << square.getArea() << " }" ; 
}

/*Overloading Relational opeartors*/
bool operator<(const SquareShape& lhs, const SquareShape& rhs)
{
	return lhs.getArea() < rhs.getArea();
}

bool operator>(const SquareShape& lhs, const SquareShape& rhs)
{
	return lhs.getArea() > rhs.getArea();
}

bool operator==(const SquareShape& lhs, const SquareShape& rhs)
{
	return (!(lhs < rhs) && !(lhs > rhs));
}

bool operator!=(const SquareShape&lhs, const SquareShape& rhs)
{
	return !(lhs == rhs);
}

bool operator<=(const SquareShape& lhs, const SquareShape& rhs)
{
	return ((lhs < rhs) || (lhs == rhs));
}

bool operator>=(const SquareShape& lhs, const SquareShape& rhs)
{
	return ((lhs > rhs) || (lhs == rhs));
}

int main(int argc, char const *argv[])
{
	SquareShape square_1;
	std::cout << square_1 << std::endl;

	SquareShape square_2(square_1); //direct initailization using copy-constuctor
	SquareShape square_3 = square_2; //Initialization copy-initialization

	square_1 = square_3;  //Assignment
	square_1 = square_1;  //self-assignment should work properly with assignment operator

	SquareShape square_4{2,2};
	SquareShape square_5{8,8};
	SquareShape square_6{2,2};

	if(square_4 == square_6)
		std::cout << "square_4 & square_6 are Equal ...." << std::endl;

	if(square_4 < square_5)
		std::cout << "square_4 smaller than square_5 ...." << std::endl;

	if(square_5 > square_6)
		std::cout << "square_6 is bigger than square_5 ...." << std::endl;

	if(square_4 != square_5)
		std::cout << "square_4 is Not Equal to square_5 ...." << std::endl;

	if(square_4 <= square_6)
		std::cout << "square_4 is less than or equal to square_6 ...." << std::endl;

	if(square_5 >= square_6)
		std::cout <<"square_5 is greater than or equal to square_6 ...." << std::endl;


	return 0;
}