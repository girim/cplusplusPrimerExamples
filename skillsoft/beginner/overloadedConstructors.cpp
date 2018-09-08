#include <iostream>

class Rectangle
{
    private:
        unsigned length_, width_;

    public:
        Rectangle();
        Rectangle(unsigned);
        Rectangle(unsigned, unsigned);
        ~Rectangle();

        unsigned getArea() const;
};

Rectangle::Rectangle() 
{
    std::cout << "constuctor() called " << std::endl;
    this->length_ = 1;
    this->width_ = 1;
}

Rectangle::Rectangle(unsigned length): length_(length) 
{
    std::cout << "constuctor(length) called " << std::endl;
};

Rectangle::Rectangle(unsigned length, unsigned width): length_(length), width_(width)
{
    std::cout << "constuctor(length, width) called " << std::endl;
};

Rectangle::~Rectangle(){};

int main(int argc, char const *argv[])
{
    Rectangle rect1;
    Rectangle rect2(4);
    Rectangle rect3(4, 16);

    return 0;
}

