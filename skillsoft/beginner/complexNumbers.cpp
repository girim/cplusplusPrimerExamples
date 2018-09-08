#include <iostream>

class ComplexNumber
{
    public:
        explicit ComplexNumber(): realPart_(1), imaginaryPart_(1){};
        ComplexNumber(unsigned realPart, unsigned imaginaryPart): realPart_(realPart), imaginaryPart_(imaginaryPart){};
        ~ComplexNumber(){};
        unsigned getRealPart() const { return realPart_; }
        unsigned getImaginaryPart() const { return imaginaryPart_; }

        void toString()
        {
            std::cout << "{" << this->realPart_ << "+i" << this->imaginaryPart_ << "}" << std::endl;
        }

        ComplexNumber operator+(const ComplexNumber &rhs)
        {
            unsigned realPart = this->realPart_ + rhs.realPart_;
            unsigned imaginaryPart = this->imaginaryPart_ + rhs.imaginaryPart_;
            return ComplexNumber(realPart, imaginaryPart);
        }

    private:
        unsigned realPart_;
        unsigned imaginaryPart_;
};

int main(int argc, char const *argv[])
{
    ComplexNumber num1(1, 3);
    ComplexNumber num2(4, 5);

    ComplexNumber num3 = num1 + num2;
    num3.toString();


    return 0;
}
