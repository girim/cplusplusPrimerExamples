#include <iostream>
#include "Parallelogram.hpp"

Parallelogram::Parallelogram(double breadth, double height, double sideLength, unsigned int angleA, unsigned int angleB) : \
                                sideLength_(sideLength), breadth_(breadth), height_(height), angleA_(angleA), angleB_(angleB) {}

Parallelogram::~Parallelogram(){}

double Parallelogram::getBreadth() const
{
    return breadth_;
}

double Parallelogram::getHeight() const 
{
    return height_;
}

double Parallelogram::getSideLength() const
{
    return sideLength_;
}

double Parallelogram::area() const
{
    return (breadth_ * height_);
}

double Parallelogram::perimeter() const
{
    return (2 * (breadth_ + sideLength_));
} 