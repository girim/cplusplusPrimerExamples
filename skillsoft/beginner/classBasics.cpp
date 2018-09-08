#include <iostream>
#define EOL "\n"

class Rectangle
{
    private:
        unsigned length_;
        unsigned width_;
    
    public:
        unsigned maxLength_ = 1000;
        Rectangle();
        Rectangle(unsigned length, unsigned width) :  length_(length), width_(width){};
        ~Rectangle();
        unsigned getArea() const;
        void setLength(unsigned length);
        void setWidth(unsigned width);
        unsigned getLength() const;
        unsigned getWidth() const;
};

Rectangle::Rectangle()
{
    this->length_ = this->width_ = 1;
}

Rectangle::~Rectangle(){}

unsigned Rectangle::getArea() const
{
    return length_ * width_;
}

void Rectangle::setLength(unsigned length)
{
    this->length_ = length;
}

void Rectangle::setWidth(unsigned width)
{
    this->width_ = width;
}

unsigned Rectangle::getLength() const
{
    return this->length_;
}

unsigned Rectangle::getWidth()  const
{
    return this->width_;
}

int main(int argc, char const *argv[])
{
    Rectangle rect1;
    //rect1.length_; //private variable cannot access with instance
    std::cout << "maxLength: " << rect1.maxLength_ << EOL;   ///public variable accessible outside

    std::cout << "length: " << rect1.getLength() << EOL;
    std::cout << "width: " << rect1.getWidth() << EOL;
    std::cout << "area: " << rect1.getArea() << EOL;
    
    Rectangle rect2(100, 120);
    std::cout << "length: " << rect2.getLength() << EOL;
    std::cout << "width: " << rect2.getWidth() << EOL;
    std::cout << "area: " << rect2.getArea() << EOL;

    return 0;
}
