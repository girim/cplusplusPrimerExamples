#ifndef __CONE_HPP__
#define __CONE_HPP__

const double PI = 3.14159;

class Cone
{
    public:
        explicit Cone(double sideLength = 1.0, double height = 1.0, double radius = 1.0);
        ~Cone();
        Cone(const Cone& cone);
        Cone& operator=(const Cone& cone);
        Cone(const Cone&& cone);

        double getSideLength() const;
        double getHeight() const;
        double getRadius() const;

        double baseArea() const;
        double sideArea() const;
        double surfaceArea() const;
        double volume() const;

    private:
        double sideLength_;
        double height_;
        double radius_;
};

inline std::ostream& operator<<(std::ostream& os, const Cone& cone)
{
    os << "{ sideLength: " << cone.getSideLength() << " , height: " << cone.getHeight() \
        << " , radius: " << cone.getRadius() << ", surfaceArea: " << cone.surfaceArea() << " }";

    os << std::endl;
    return os; 
}

inline bool operator<(const Cone& lhs, const Cone& rhs)
{
    return (lhs.getSideLength() < rhs.getSideLength() && \
                lhs.getHeight() < rhs.getHeight() && \
                    lhs.getRadius() < rhs.getRadius());
}

inline bool operator==(const Cone& lhs, const Cone& rhs)
{
    return (lhs.getSideLength() == rhs.getSideLength() && \
                lhs.getHeight() == rhs.getHeight() && \
                    lhs.getRadius() == rhs.getRadius());
}

inline bool operator>(const Cone& lhs, const Cone& rhs)
{
    return (lhs.getSideLength() > rhs.getSideLength() && \
                lhs.getHeight() > rhs.getHeight() && \
                    lhs.getRadius() > rhs.getRadius());
}

inline bool operator!=(const Cone& lhs, const Cone& rhs)
{
    return !(lhs == rhs);
}

inline bool operator<=(const Cone& lhs, const Cone& rhs)
{
    return ((lhs == rhs) || (lhs < rhs));
}

inline bool operator>=(const Cone& lhs, const Cone& rhs)
{
    return ((lhs == rhs) || (lhs > rhs));
}

#endif // !__CONE_HPP__

