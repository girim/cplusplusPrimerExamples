#ifndef __CYLINDER_HPP__
#define __CYLINDER_HPP__

#include <iostream>

const double PI = 3.14159;

class Cylinder
{
    public:
        explicit Cylinder(double height = 1.0, double radius = 1.0);
        ~Cylinder();
        Cylinder(const Cylinder& cylinder);
        Cylinder& operator=(const Cylinder& cylinder);
        Cylinder(const Cylinder&& cylinder) noexcept;

        double getHeight() const;
        double getRadius() const;
        double surfaceAreaOfBothEnds() const;
        double surfaceAreaOfSide() const;
        double surfaceArea() const;
        double volume() const;

    private:
        double height_;
        double radius_;
};

inline std::ostream& operator<<(std::ostream& os, const Cylinder& cylinder)
{
    os << "{ SurfaceArea : " << cylinder.surfaceArea() << ", Height: " << cylinder.getHeight() \
        << ", Radius: " << cylinder.getRadius() << " }";
    return os; 
}

inline bool operator==(const Cylinder& lhs, const Cylinder& rhs)
{
    return (lhs.getHeight() ==  rhs.getHeight() && \
                lhs.getRadius() == rhs.getRadius() && \
                    lhs.surfaceArea() == rhs.surfaceArea());
}

inline bool operator!=(const Cylinder& lhs, const Cylinder& rhs)
{
    return !(lhs == rhs);
}

inline bool operator<(const Cylinder& lhs, const Cylinder& rhs)
{
    return (lhs.getHeight() < rhs.getHeight() && \
                lhs.getRadius() < rhs.getRadius() && \
                    lhs.surfaceArea() < rhs.surfaceArea());
}

inline bool operator>(const Cylinder& lhs, const Cylinder& rhs)
{
    return (lhs.getHeight() > rhs.getHeight() && \
                lhs.getRadius() > rhs.getRadius() && \
                    lhs.surfaceArea() > rhs.surfaceArea());
}

inline bool operator<=(const Cylinder& lhs, const Cylinder& rhs)
{
    return ((lhs < rhs) || (lhs == rhs));
}

inline bool operator>=(const Cylinder& lhs, const Cylinder& rhs)
{
    return ((lhs > rhs) || (lhs == rhs));
}

#endif //__CYLINDER_HPP__