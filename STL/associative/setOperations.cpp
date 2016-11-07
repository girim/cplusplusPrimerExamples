#include <iostream>
#include <set>
#include <string>
#include <functional>

class Trapeziod
{
public:
	Trapeziod(double side_a = 0, double side_b = 0, double height = 0) : \
		sideA_(side_a), sideB_(side_b), height_(height){};

	~Trapeziod(){};

	double getArea() const
	{
		return ((0.5 * (sideA_+ sideB_)) * height_);
	}

	double getSideA() const { return sideA_; }
	double getSideB() const { return sideB_; }
	double getHeight() const { return height_;}

private:
	double sideA_;
	double sideB_;
	double height_;
};

//overloading output operator
std::ostream& operator<<(std::ostream &os, const Trapeziod& trapeziod)
{
	char delimiter = ',';
	os << "{ " << "a: " << trapeziod.getSideA() << delimiter \
				<< " b: " << trapeziod.getSideB() << delimiter \
					<< " h: " << trapeziod.getHeight() << delimiter \
						<< " Area = " << trapeziod.getArea() << " }";
	return os;
}

void drawDottedLine()
{
	std::cout << "------------------------" << std::endl;
}

template<typename X>
void print(const X& container, std::string name ="")
{
	drawDottedLine();
	for(typename X::const_iterator iter = container.cbegin(); \
			iter != container.cend(); ++iter)
	{
		std::cout << "Key/Value is: " << *iter << std::endl;
	}
	drawDottedLine();
}

template<typename R>
void printInReverse(const R& container, std::string name = "")
{
	drawDottedLine();
	for(typename R::const_reverse_iterator iter = container.crbegin(); \
			iter != container.crend(); ++iter)
	{
		std::cout << "Key/Value[Reverse] is: " << *iter << std::endl;
	}
	drawDottedLine();
}

int main(int argc, char const *argv[])
{
	/*No Duplicate values allowed KEY==VALUE*/
	std::set<int> firstSet = {1,1,2,3,4};
	print(firstSet);

	std::set<int> secondSet(firstSet.begin(), firstSet.end());
	print(secondSet);
	printInReverse(secondSet);

	secondSet.insert(8);
	print(secondSet);

	std::function<bool(Trapeziod, Trapeziod)> compare = [](const Trapeziod& lhs, const Trapeziod& rhs){
		return (lhs.getArea() < rhs.getArea());
	};

	Trapeziod t1(1.2, 2.3, 3.4);
	Trapeziod t2(9.1, 9.2, 9.3);
	Trapeziod t3(4.5, 8.9, 4.4);
	Trapeziod t4(5.6, 6.7, 7.8);
	Trapeziod t5;

	std::set<Trapeziod, decltype(compare)> shapes(compare);
	shapes.insert(t1);
	shapes.insert(t2);
	shapes.insert(t3);
	shapes.insert(t4);

	print(shapes);
	printInReverse(shapes);

	std::cout << "Count of t1 : " << shapes.count(t4) << std::endl;
	std::cout << "Count of t5 : " << shapes.count(t5) << std::endl;

	firstSet.erase(firstSet.begin());
	print(firstSet, "firstSet");

	firstSet.erase(4);
	print(firstSet, "firstSet");

	std::set<Trapeziod>::iterator iter = shapes.lower_bound(t3);
	std::cout << "Lower bound Value: " << *iter << std::endl;

	iter = shapes.upper_bound(t3);
	std::cout << "Upper bound Value: " << *iter << std::endl;
	
	return 0;
}