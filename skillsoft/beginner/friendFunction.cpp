#include <iostream>

class Point
{
    public:
        explicit Point(int x = 0, int y = 0) : x_(x), y_(y){}
        ~Point(){};

        friend void canAccessPrivateMembers();

        int getX() const { return this->x_; }
        int getY() const { return this->y_; }

    private:
        int x_;
        int y_;
};


void canAccessPrivateMembers()
{
    Point point;
    std::cout << "x value: " << point.getX() << std::endl;
    point.x_ = 10;
    std::cout << "x value: " << point.getX() << std::endl;
}


int main(int argc, char const *argv[])
{
    canAccessPrivateMembers();
    return 0;
}
