#include <iostream>

class Rectangle
{
    public:
        Rectangle() = default;
        explicit Rectangle(unsigned);
        explicit Rectangle(unsigned, unsigned);
        ~Rectangle();

        unsigned getWidth() const;
        unsigned getHeight() const;

    private:
        unsigned width_ = 1;
        unsigned height_ = 1;
};

Rectangle::Rectangle(unsigned n) : width_(n), height_(n)
{}

Rectangle::Rectangle(unsigned width, unsigned height) : width_(width), height_(height)
{}

Rectangle::~Rectangle(){}

unsigned Rectangle::getWidth() const
{
    return this->width_;
}

unsigned Rectangle::getHeight() const
{
    return this->height_;
}

int main(int argc, char const *argv[])
{
    Rectangle rect_1{};
    std::cout << "Width: " << rect_1.getWidth() << "\n";

    Rectangle *ptrToRect =  &rect_1;
    std::cout << "Height: " << ptrToRect->getHeight() << "\n";

    Rectangle *ptr = new Rectangle;
    std::cout << "height: " << ptr->getHeight() << "\n";
    std::cout << "width: " << ptr->getWidth() << "\n";

    delete ptr;

    return 0;
}

