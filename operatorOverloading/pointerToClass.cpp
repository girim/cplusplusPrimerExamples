#include <iostream>
#include <string>
void leaveALineSpaceHere();

class Box
{
public:
	Box(int length = 1, int breadth = 1, int height = 1): \
	    length_(length), breadth_(breadth), height_(height)
	{
		std::cout <<"Box is created with length: " << length_ << \
		  " breadth: " << breadth_ << " height: " << height_ << std::endl;
	};

	~Box()
	{
		std::cout << boxName_ <<" is destroyed ..." << std::endl;
	};

    int getLength(){return length_;}
    int getHeight(){ return height_; }
    int getBreadth(){return breadth_;}
    std::string boxName_;

private:
	int length_;
	int breadth_;
	int height_;
};

//Pointers to class members of class type Box.
std::string Box::*ptrToBoxName = &Box::boxName_;
int (Box::*ptrToGetLength)() = &Box::getLength;
int (Box::*ptrToGetHeight)() = &Box::getHeight;
int (Box::*ptrToGetBreadth)() = &Box::getBreadth;

void leaveALineSpaceHere()
{
   std::cout <<"" << std::endl;
}

int main()
{
    Box smallBox;
    smallBox.boxName_ = "smallbox";

    Box mediumBox(7, 8, 9);
    mediumBox.boxName_ = "mediumbox";

    Box largeBox(100,200,300);
    largeBox.boxName_ = "largebox";

    Box giftBox(20,40,60);
    giftBox.boxName_ = "giftbox";
    Box *ptrToGiftBox = &giftBox;


    leaveALineSpaceHere();
    //Pointer to class smallBox
    Box *ptrToSmallBox = &smallBox;
    std::cout << "BoxName: " << (*ptrToSmallBox).boxName_     << std::endl;
    std::cout << "length: "  << (*ptrToSmallBox).getLength()  << std::endl;
    std::cout << "breadth: " << (*ptrToSmallBox).getBreadth() << std::endl;
    std::cout << "height: "  << (*ptrToSmallBox).getHeight()  << std::endl;
    
    leaveALineSpaceHere();
    //Pointer to class mediumBox
    Box *ptrToMediumBox = &mediumBox;
    std::cout << "BoxName: " << ptrToMediumBox->boxName_     << std::endl;
    std::cout << "length: "  << ptrToMediumBox->getLength()  << std::endl;
    std::cout << "breadth: " << ptrToMediumBox->getBreadth() << std::endl;
    std::cout << "height: "  << ptrToMediumBox->getHeight()  << std::endl;

    leaveALineSpaceHere();
    //Using pointer to class Box members
    //.* is a member access operator
    std::cout << "BoxName: " << largeBox.*ptrToBoxName        << std::endl;
    std::cout << "length: "  << (largeBox.*ptrToGetLength)()  << std::endl;
    std::cout << "breadth: " << (largeBox.*ptrToGetBreadth)() << std::endl;
    std::cout << "height: "  << (largeBox.*ptrToGetHeight)()  << std::endl;
   
    leaveALineSpaceHere();
    //Accessing class members using pointer to class
    std::cout << "BoxName: " << ptrToGiftBox->*ptrToBoxName        << std::endl;
    std::cout << "length: "  << (ptrToGiftBox->*ptrToGetLength)()  << std::endl;
    std::cout << "breadth: " << (ptrToGiftBox->*ptrToGetBreadth)() << std::endl;
    std::cout << "height: "  << (ptrToGiftBox->*ptrToGetHeight)()  << std::endl;
 
    leaveALineSpaceHere();
	return 0;
}

