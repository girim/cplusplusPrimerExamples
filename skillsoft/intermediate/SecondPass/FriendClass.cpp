#include <iostream>

class X 
{   
    public:
        explicit X() : x_(0), y_(0) {};
        ~X(){};

        unsigned getX() const { return this->x_; };
        unsigned getY() const { return this->y_; };

        /* frind class declaration */
        friend class Friend;

    private:
        unsigned x_;
        unsigned y_;
};

class Friend
{
    public:
        explicit Friend() {};
        ~Friend(){};

        void incrementCoordinates(X &x)
        {
            ++x.x_;
            ++x.y_;
        }
};

int main(int argc, char const *argv[])
{
    X x{};
    Friend frnd{};

    std::cout << "x value: " << x.getX() << "\n";
    std::cout << "x value: " << x.getY() << "\n";
    frnd.incrementCoordinates(x);
    std::cout << "x value: " << x.getX() << "\n";
    std::cout << "x value: " << x.getY() << "\n";

    return 0;
}
