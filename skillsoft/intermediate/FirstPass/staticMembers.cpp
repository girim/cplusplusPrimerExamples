#include <iostream>

class Box
{
    public:
        explicit Box(double length = 1, double width = 1, double height = 1) : length_(length), width_(width), height_(height) 
        {
             ++counter_;
        }
        ~Box(){};

        double getLength() const { return this->length_; };
        double getWidth() const { return this->width_; };
        double getHeight() const { return this->height_;};

        void setLength(double length) { this->length_ = length;}
        void setWidth(double width) { this->width_ = width;}
        void setHeight(double height) { this->height_ = height;}

        static unsigned getObjectCount()
        {
            return counter_;
        }

        /* Non-static member functions can access static member variable */
        unsigned getCounter()
        {
            return counter_;
        }
    
    private:
        static unsigned counter_;
        double length_;
        double width_;
        double height_;
};

unsigned Box::counter_ = 0;

void someFunction()
{
    static unsigned someVar = 0;
    ++someVar;

    std::cout << "Value of someVar: " << someVar << "\n";
}

int main(int argc, char const *argv[])
{
    Box box{}, box_1{2, 2, 2}, box_2{4, 4, 4};
    std::cout << "Box count: " << Box::getObjectCount() << "\n";
    //std::cout << "Box count: " << Box::counter_ << "\n";
    std::cout << "Box count: " << box_1.getCounter() << "\n";

    someFunction();
    someFunction();
    someFunction();

    return 0;
}
