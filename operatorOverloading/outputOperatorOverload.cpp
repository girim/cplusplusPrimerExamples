#include <iostream>
using namespace std;


class Rectangle
{
public:
	Rectangle(unsigned int length = 0, unsigned int breadth = 0 ): length_(length), breadth_(breadth){}

	~Rectangle(){}

    unsigned int getLength()
    { 
   		return length_;
    }
 
    void setLength(unsigned int length)
    {
    	length_ = length;
    }

    unsigned int getBreadth()
    {
   		return breadth_;
    }

    void setBreadth(unsigned int breadth)
    {
    	breadth_ = breadth;
    }

    unsigned long getArea()
    {
    	return length_ * breadth_;
    }
   
private:
   unsigned int length_;
   unsigned int breadth_;

};


//Overloading INPUT stream
istream &operator>>(istream &inputStream, Rectangle& rectangle)
{
	unsigned int length = 0;
	unsigned int breadth = 0;
	inputStream >> length >> breadth;

	if (inputStream)
	{
		rectangle.setLength(length);
		rectangle.setBreadth(breadth);
	}
	else
	{
        rectangle.setLength(0);
        rectangle.setBreadth(0);
	}

	return inputStream;
}


//Overloading OUTPUT stream
ostream &operator<<(ostream &outputStream, const Rectangle& rectangle)
{
	outputStream << "Length: " << rectangle.getLength() \
				<< "| Breadth: " << rectangle.getBreadth() \
				<< "| Area: " << rectangle.getArea();
    return outputStream;
}

int main()
{
    Rectangle rectOne(10,20);
    std::cout << rectOne << std::endl;

    Rectangle rectTwo;
    std::cin >> rectTwo;

    std::cout << rectTwo << std::endl;
	return 0;
}