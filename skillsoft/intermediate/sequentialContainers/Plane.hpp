#ifndef __PLANE_HPP__
#define __PLANE_HPP__

#include <iostream>

class Plane
{
    public:
        //Plane() = default;
        explicit Plane(double length = 0, double width = 0);
        ~Plane();
        Plane(const Plane& plane);
        Plane& operator=(const Plane& plane);
        Plane(Plane&& plane) noexcept;
        
        double getAreaOfPlane() const;
        double getLength() const;
        double getWidth() const;


    private:
        double length_;
        double width_;
};

#endif //__PLANE_HPP__
