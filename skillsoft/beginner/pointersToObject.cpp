#include <iostream>

class Rectangle
{
    private:
        int length_, width_;

    public:
        Rectangle();
        Rectangle(int length);
        Rectangle(int length, int width);
        ~Rectangle();

        int getArea() const;
};

Rectangle::Rectangle()
{
    this->length_ = this->width_ = 1;
}

Rectangle::Rectangle(int length) : length_(length)
{
    this->width_ = this->length_;    
}

Rectangle::Rectangle(int length, int width) : length_(length), width_(width) {};

Rectangle::~Rectangle(){};

int Rectangle::getArea() const
{
    return length_ * width_;
}

int main(int argc, char const *argv[])
{
    Rectangle *rect1 = new Rectangle;
    Rectangle *rect2 = new Rectangle(10);
    Rectangle *rect3 = new Rectangle(20, 40);

    std::cout << "Area of rect1: " << rect1->getArea() << std::endl;
    std::cout << "Area of rect2: " << rect2->getArea() << std::endl;
    std::cout << "Area of rect3: " << rect3->getArea() << std::endl;

    delete rect1;
    delete rect2;
    delete rect3;

    return 0;
}

