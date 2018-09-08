#include <iostream>
#include <cstdlib>


class Point
{
    public:
        explicit Point();
        explicit Point(unsigned);
        explicit Point(unsigned, unsigned);
        ~Point();

        unsigned getX() const;
        unsigned getY() const;

        void setX(unsigned);
        void setY(unsigned);

        /* prefix increment operator */
        void operator++()
        {
            ++this->x_;
            ++this->y_;
        }

        /* postfix increment operator */
        void operator++(int)
        {
            this->x_++;
            this->y_++;
        }

        /* prefix decrement operator */
        void operator--()
        {
            --this->x_;
            --this->y_;
        }

        /* postfix decrement operator */
        void operator--(int)
        {
            this->x_--;
            this->y_--;
        }

    private:
        unsigned x_;
        unsigned y_;
};

Point::Point() : x_(0), y_(0){};

Point::Point(unsigned n) : x_(n), y_(n){};

Point::Point(unsigned x, unsigned y): x_(x), y_(y){};

Point::~Point(){};

unsigned Point::getX() const
{
    return this->x_;
}

unsigned Point::getY() const
{
    return this->y_;
}

void Point::setX(unsigned x)
{
    this->x_ = x;
}

void Point::setY(unsigned y)
{
    this->y_ = y;
}

std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "{x:" << point.getX() << ",y:" << point.getY() << "}";
    return os; 
}

/* Arithmetic operators */
Point operator+(const Point& point1, const Point& point2)
{
    Point resultPt{};
    resultPt.setX(point1.getX() + point2.getX());
    resultPt.setY(point1.getY() + point2.getY());

    return resultPt;
}

Point operator-(const Point& point1, const Point& point2)
{
    Point resultPt{};
    resultPt.setX(abs(point1.getX() - point2.getX()));
    resultPt.setY(abs(point1.getY() - point2.getY()));

    return resultPt;
}

Point operator*(const Point& point1, const Point& point2)
{
    Point resultPt{};
    resultPt.setX(point1.getX() * point2.getX());
    resultPt.setY(point1.getY() * point2.getY());

    return resultPt;
}

Point operator/(const Point& point1, const Point& point2)
{
    Point resultPt{};
    resultPt.setX(point1.getX() / point1.getX());
    resultPt.setY(point1.getY() / point1.getY());

    return resultPt;
}

/* Relational operators overloading */
bool operator<(const Point& point1, const Point& point2)
{
    return ((point1.getX() < point2.getX())&&(point1.getY() < point2.getY()));
}

bool operator>(const Point& point1, const Point& point2)
{
    return !(point1 < point2);
}

bool operator==(const Point& point1, const Point& point2)
{
    return ((point1.getX() == point2.getX()) && (point1.getY() == point2.getY()));
}

bool operator!=(const Point& point1, const Point& point2)
{
    return !(point1 == point2);
}

int main(int argc, char const *argv[])
{
    Point point{}, point1{1};
    std::cout << point << "\n";
    
    ++point;
    std::cout << point << "\n";
    
    point++;
    std::cout << point << "\n";

    --point;
    std::cout << point << "\n";

    ++point;
    point--;
    std::cout << point << "\n";

    std::cout << point + point1 << "\n";
    std::cout << point - point1 << "\n";
    std::cout << point * point1 << "\n";
    std::cout << point / point1 << "\n";

    std::cout << (point < point1) << "\n";
    std::cout << (point > point1) << "\n";
    std::cout << (point == point1) << "\n";
    std::cout << (point != point1) << "\n";

    return 0;
}

