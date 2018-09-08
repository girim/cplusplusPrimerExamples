#include "Cylinder.hpp"

Cylinder::Cylinder(double height, double radius) : height_(height), radius_(radius){}

Cylinder::~Cylinder()
{
    //std::cout << "destructor called ..." << std::endl;
}

Cylinder::Cylinder(const Cylinder& cylinder)
{
    this->height_ = cylinder.getHeight();
    this->radius_ = cylinder.getRadius();
}

Cylinder& Cylinder::operator=(const Cylinder& cylinder)
{
    this->height_ = cylinder.getHeight();
    this->radius_ = cylinder.getRadius();

    return *this;
}

Cylinder::Cylinder(const Cylinder&& cylinder) noexcept
{
    this->height_ = cylinder.getHeight();
    this->radius_ = cylinder.getRadius();
}

double Cylinder::getHeight() const
{
    return height_;
}

double Cylinder::getRadius() const
{
    return radius_;
}

double Cylinder::surfaceAreaOfBothEnds() const
{
    return (2 * PI * radius_ * radius_);
}

double Cylinder::surfaceAreaOfSide() const
{
    return (2 * PI * radius_ * height_);
}

double Cylinder::surfaceArea() const
{
    return (2 * PI * radius_ * (radius_ + height_));
}

double Cylinder::volume() const
{
    return (PI * (radius_ * radius_) * height_);
}

