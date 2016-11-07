#include "Plane.hpp"

Plane::Plane(double length, double width) : length_(length), width_(width) {};
Plane::~Plane()
{
    std::cout << "Plane destroyed " << std::endl;
};

Plane::Plane(const Plane& plane)
{
    std::cout << "Plane copy-constructor" << std::endl;
    this->length_ =  plane.length_;
    this->width_  =  plane.width_;
}

Plane& Plane::operator=(const Plane& plane)
{
    std::cout << "Plane copy-assignment operator" << std::endl;
    this->length_ =  plane.length_;
    this->width_  =  plane.width_;
            
    return *this;
}

Plane::Plane(Plane&& plane) noexcept
{
    std::cout << "Plane move-constructor" << std::endl;
    this->length_ = plane.length_;
    this->width_  = plane.width_;
}

double Plane::getLength() const
{
    return length_;
}

double Plane::getWidth() const
{
    return width_;
}

double Plane::getAreaOfPlane() const
{
    return length_ * width_;
}

