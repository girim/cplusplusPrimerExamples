#include <iostream>


class Rectangle
{
    public:
        explicit Rectangle(unsigned);
        explicit Rectangle(unsigned, unsigned);
        ~Rectangle();

        unsigned getWidth() const;
        unsigned getHeight() const;

        void setWidth(const unsigned&);
        void setHeight(const unsigned&);

    private:
        unsigned width_;
        unsigned height_;
};

Rectangle::Rectangle(unsigned n = 1): width_(n), height_(n){}

Rectangle::Rectangle(unsigned width, unsigned height) : width_(width), height_(height){}

Rectangle::~Rectangle(){}

unsigned Rectangle::getWidth() const 
{
    return this->width_;
}

unsigned Rectangle::getHeight() const
{
    return this->height_;
}

void Rectangle::setWidth(const unsigned& width)
{
    this->width_ = width;
}

void Rectangle::setHeight(const unsigned& height)
{
    this->height_ = height;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle)
{
    os << "{ Height: " << rectangle.getHeight() << " ,Width: " << rectangle.getWidth() << " } \n";
    return os;
}

int main(int argc, char const *argv[])
{
    Rectangle rect_1{};
    std::cout << "width of rect_1: " << rect_1.getWidth() << "\n";
    std::cout << "height of rect_1: " << rect_1.getHeight() << "\n";

    Rectangle rect_2{2};
    std::cout << "width of rect_2: " << rect_2.getWidth() << "\n";
    std::cout << "height of rect_2: " << rect_2.getHeight() << "\n";

    Rectangle rect_3{3, 4};
    std::cout << "width of rect_3: " << rect_3.getWidth() << "\n";
    std::cout << "height of rect_3: " << rect_3.getHeight() << "\n";

    rect_1.setHeight(10);
    rect_1.setWidth(20);

    const Rectangle rect_4{};
    //rect_4.setWidth(3);
    std::cout << rect_4 ;

    return 0;
}
