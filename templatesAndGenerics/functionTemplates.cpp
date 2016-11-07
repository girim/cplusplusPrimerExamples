#include <iostream>
#include <vector>
#include <functional>
#include <cstring>

//User defined type
class Box
{
public:
	Box(double height = 0.0,  double width = 0.0, double length = 0.0) : 
		height_(height), width_(width), length_(length) {};

    double getHeight() const
    {
    	return height_;
    }

    double getWidth() const
    {
    	return width_;
    }

    double getLength() const
    {
    	return length_;
    }

	~Box(){};

private:
	double height_;
	double width_;
	double length_;
};

// Function templates
template <typename T>
int compare(const T& left, const T& right)
{
	// std::less used here compares the un-related pointers also
	if (std::less<T>()(left, right)) return -1;
	if (std::less<T>()(right, left)) return 1;

	return 0;
}

//NonType Template parameters(Takes value rather than Types)
template <unsigned M, unsigned N>
int compareString(const char (&leftArray)[M], const char (&rightArray)[N])
{
	return strcmp(leftArray, rightArray);
}

/*Arithmetic, Relational, Equality, Relational, Bitwise opertors should be non-member
  overloaded functions because they are symmetric opearations */
bool operator<(const Box& leftBox, const Box& rightBox)
{
	std::cout << "Overloaded \" < \" operator called: " << std::endl;
	return ((leftBox.getWidth() * leftBox.getHeight() * leftBox.getLength()) \
				< (rightBox.getWidth() * rightBox.getHeight() * rightBox.getLength()));
}

int main()
{
	std::vector<int> listOne = {1, 2, 3, 4};
	std::vector<int> listTwo = {5, 6, 7};
	Box boxOne(1, 2, 3);
	Box boxTwo(4, 5, 6);

	std::cout << "Result : vector compare : " << compare(listOne, listTwo) << std::endl;
	std::cout << "Result : int compare    : " << compare(10, 20) << std::endl;
    std::cout << "Result : double compare : " << compare(3.44, 1.22) << std::endl;
    std::cout << "Result : Box compare    : " << compare(boxOne, boxTwo) << std::endl;      

    std::cout << "Comparing two strings: " << compareString("Hi", "Hello") << std::endl;
    std::cout << "size of unsigned: " << sizeof(unsigned) << std::endl;

	return 0;
}