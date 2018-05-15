#ifndef __PARALLELOGRAM_HPP__
#define __PARALLELOGRAM_HPP__

class Parallelogram
{
    public:
        explicit Parallelogram(double breadth = 1.0, double height = 1.0, \ 
                                  double sideLength = 1.0,  unsigned int angleA = 90, unsigned int angleB = 90);
        ~Parallelogram();

        double getBreadth() const;
        double getHeight() const;
        double getSideLength() const;
        unsigned int getAngleA() const;
        unsigned int getAngleB() const;
        double area() const;
        double perimeter() const;
        
    private:
        double breadth_;
        double height_;
        double sideLength_;
        unsigned int angleA_;
        unsigned int angleB_;
};

#endif