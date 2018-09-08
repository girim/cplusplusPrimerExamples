#include <iostream>


class Rectangle
{
    private:
        unsigned *length_, *width_;

    public:
        Rectangle(unsigned length, unsigned width) : length_(new unsigned), width_(new unsigned)
        {
            *length_ = length;
            *width_ = width;
        }

        ~Rectangle()
        {
            std::cout << "Destrutor called" << std::endl;
            delete length_;
            delete width_;
        }

        unsigned getArea() const 
        {
            return ((*length_) * (*width_));
        }
};

int main(int argc, char const *argv[])
{
    Rectangle rect(20, 40);
    std::cout << "Area is : " << rect.getArea() << std::endl;
    
    return 0;
}



