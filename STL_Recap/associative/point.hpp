#ifndef __POINT_HPP__
#define __POINT_HPP__
#include <initializer_list>
#include <iostream>

class Point
{
    public:
        explicit Point(): x_(0), y_(0)
        {

        }
        explicit Point(unsigned x, unsigned y) : x_(x), y_(y)
        {
            //std::cout << "Point constructor called " << std::endl;
        }

        explicit Point(unsigned n): x_(n), y_(n)
        {
            
        }

        ~Point()
        {
            //std::cout << "Point destructor called" << std::endl;
        }

        Point(const Point& point)
        {
            //std::cout << "Point copy-constructor called " << std::endl;
            this->x_ = point.x_;
            this->y_ = point.y_;
        }

        Point& operator=(const Point& point)
        {
            //std::cout << "Point copy-assignment called " << std::endl;
            this->x_ = point.x_;
            this->y_ = point.y_;

            return *this;
        }

        std::size_t operator()(const Point& pt) const
        {
            std::size_t xHash = std::hash<unsigned>()(pt.getX());
            std::size_t yHash = std::hash<unsigned>()(pt.getY());

            //std::cout << "xHash: " << xHash  << " yHash: " << yHash << "\n";
            //std::cout << "FinalHash: " << (xHash + yHash) << "\n"; 
            return  (xHash + yHash);
        }

        unsigned getX() const { return this->x_;};
        unsigned getY() const { return this->y_;};

        void setX(unsigned x) 
        {
            this->x_ = x;
        } 

        void setY(unsigned y) 
        {
            this->y_ = y;
        }

    private:
        unsigned x_;
        unsigned y_;
};

std::ostream& operator<<(std::ostream &os, const Point& point)
{
    os << "{x:" << point.getX() << ",y:" << point.getY() << "}";
    return os;
}

bool operator==(const Point& lhs, const Point& rhs)
{
    //std::cout << "comparing two points: " << lhs << " " << rhs << "\n";
    return ((lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY()));
}

bool operator!=(const Point& lhs, const Point& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const Point& lhs, const Point& rhs)
{
    return ((lhs.getX() < rhs.getX()) && (lhs.getY() < rhs.getY()));
}

bool operator>(const Point& lhs, const Point& rhs)
{
    return ((lhs.getX() > rhs.getX()) && (lhs.getY() > rhs.getY()));
}

#endif //__POINT_HPP__