#include <iostream>

struct Kite 
{
    Kite();
    Kite(int sideLengthA, int sideLengthB, int diagonalP, int diagonalQ);
    ~Kite();
    double getArea() const;

    private:
        int sideLengthA_;
        int sideLengthB_;
        int diagonalP_;
        int diagonalQ_;
};

Kite::Kite(){
    this->sideLengthA_ = this->sideLengthB_ = 2;
    this->diagonalP_ = 9;
    this->diagonalQ_ = 10;
}

Kite::Kite(int sideLengthA, int sideLengthB, int diagonalP, int diagonalQ) : \
            sideLengthA_(sideLengthA), sideLengthB_(sideLengthB), diagonalP_(diagonalP), diagonalQ_(diagonalQ) {}
Kite::~Kite(){}

double Kite::getArea() const
{
    return ((this->diagonalP_ * this->diagonalQ_) / 2);
}

int main(int argc, char const *argv[])
{
    Kite kite;
    std::cout << "Area of Kite: " << kite.getArea() << std::endl;

    return 0;
}


