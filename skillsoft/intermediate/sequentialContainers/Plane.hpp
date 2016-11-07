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
        
        friend std::ostream& operator<<(std::ostream& os, const Plane& plane);

    private:
        double length_;
        double width_;
};

inline std::ostream& operator<<(std::ostream& os, const Plane& plane)
{
    os << "{ length: " << plane.getLength() <<  " width: " << plane.getWidth() \
        << " Area: " << plane.getAreaOfPlane() << " }";

    return os;
}

inline bool operator<(const Plane& lhs, const Plane& rhs)
{
    return (lhs.getLength() < rhs.getLength() && lhs.getWidth() < rhs.getWidth() && \
                lhs.getAreaOfPlane() < rhs.getAreaOfPlane());
}

inline bool operator>(const Plane& lhs, const Plane& rhs)
{
    return (lhs.getLength() > rhs.getLength() && lhs.getWidth() > rhs.getWidth() && \
                lhs.getAreaOfPlane() > rhs.getAreaOfPlane());
}

inline bool operator==(const Plane& lhs, const Plane& rhs)
{
    return (lhs.getLength() == rhs.getLength() && lhs.getWidth() == rhs.getWidth() && \
                lhs.getAreaOfPlane() == rhs.getAreaOfPlane());
}

inline bool operator!=(const Plane& lhs, const Plane& rhs)
{
    return !(lhs == rhs);
}

inline bool operator<=(const Plane& lhs, const Plane& rhs)
{
    return ((lhs < rhs) || (lhs == rhs));
}

inline bool operator>=(const Plane& lhs, const Plane& rhs)
{
    return ((lhs > rhs) || (lhs == rhs));
}

#endif //__PLANE_HPP__
