#ifndef __POINT_HPP__
#define __POINT_HPP__
#include <initializer_list>
#include <iostream>

class Point
{
    public:
        explicit Point(unsigned x= 0, unsigned y = 0) : x_(x), y_(y)
        {
            std::cout << "Point constructor called " << std::endl;
        }
        ~Point()
        {
            std::cout << "Point destructor called" << std::endl;
        }

        Point(const Point& point)
        {
            std::cout << "Point copy-constructor called " << std::endl;
            this->x_ = point.x_;
            this->y_ = point.y_;
        }

        Point& operator=(const Point& point)
        {
            std::cout << "Point copy-assignment called " << std::endl;
            this->x_ = point.x_;
            this->y_ = point.y_;

            return *this;
        }

        unsigned getX() const { return x_;};
        unsigned getY() const { return y_;};

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

#endif //__POINT_HPP__