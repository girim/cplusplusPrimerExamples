#include <iostream>

class Box
{
public:
	Box(unsigned int length = 0, unsigned int breadth = 0, unsigned int height = 0) :
		length_(length), breadth_(breadth), height_(height) {};
	~Box(){};

	unsigned int getLength()
	{
		return length_;
	}

	unsigned int getBreadth()
	{
		return breadth_;
	}

	unsigned int getHeight()
	{
		return height_;
	}

private:
	unsigned int length_;
	unsigned int breadth_;
	unsigned int height_;
};


//overloading == operator
bool operator==(const Box& lhs, const Box& rhs)
{
   return (lhs.getLength() == rhs.getLength() &&
   		lhs.getBreadth() == rhs.getBreadth() &&
   		lhs.getHeight() == rhs.getHeight());
}

//oerloading != operator
bool operator!=(const Box& lhs, const Box& rhs)
{
   return !(lhs == rhs);
}

int main()
{
 	Box boxOne(10,10,10);
 	Box boxTwo(20,20,20);
 	Box boxThree(10,10,10);
    Box boxFour(10,10,10);

 	if (!(boxOne == boxTwo))
 	{
 		std::cout << "boxOne and boxTwo are Not Equal...." << std::endl;
 	}

 	if (boxOne == boxThree)
 	{
 		std::cout << "boxOne and boxThree are Equal...." << std::endl;
 	}

    if ((boxOne == boxThree) &&(boxThree == boxFour) && (boxFour == boxOne))
    {
    	std::cout << "boxOne, boxThree, boxFour are Equal...." << std::endl;
    }

    return 0;
}