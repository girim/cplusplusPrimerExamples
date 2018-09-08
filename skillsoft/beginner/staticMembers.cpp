#include <iostream>

class Box
{
    public:

        explicit Box(unsigned length = 1, unsigned breadth = 1, unsigned height = 1) : length_(length), breadth_(breadth), height_(height)
        {
            ++boxCount_;
        }

        ~Box(){};

        static unsigned  getBoxCount()  //static member function
        {
            return boxCount_;
        }

    private:
        static unsigned boxCount_;
        unsigned length_;
        unsigned breadth_;
        unsigned height_;
};

unsigned Box::boxCount_ = 0;

int main(int argc, char const *argv[])
{
    Box b1;
    Box b2(1, 4, 5);

    std::cout << "Number of Box instances: " << Box::getBoxCount() << std::endl;
    return 0;
}
