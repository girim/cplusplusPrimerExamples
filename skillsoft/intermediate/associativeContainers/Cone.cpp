#include <iostream>
#include "Cone.hpp"

Cone::Cone(double sideLength, double height, double radius) : \
    sideLength_(sideLength), height_(height), radius_(radius) {}

Cone::~Cone(){}

Cone::Cone(const Cone& cone)
{
    this->sideLength_ = cone.sideLength_;
    this->height_ = cone.height_;
    this->radius_ = cone.radius_;
}

Cone& Cone::operator=(const Cone& cone)
{
    this->sideLength_ = cone.sideLength_;
    this->height_ = cone.height_;
    this->radius_ = cone.radius_;

    return *this;
}

double Cone::getSideLength() const
{
    return sideLength_;
}

double Cone::getHeight() const
{
    return height_;
}

double Cone::getRadius() const
{
    return radius_;
}

double Cone::sideArea() const
{
    return ( PI * radius_ * radius_);
}

double Cone::baseArea() const
{
    return ( PI * radius_ * sideLength_); 
}

double Cone::surfaceArea() const
{
    return ( PI * radius_ * (radius_ + sideLength_));
}

double Cone::volume() const
{
    return ( (1/3) * PI * radius_ * radius_ * height_);
}
