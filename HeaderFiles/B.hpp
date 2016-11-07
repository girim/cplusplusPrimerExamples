#ifndef __B_HPP__
#define __B_HPP__

class B
{
    public:
        B(int data = 0);
        ~B();
        int getData();

    private:
        int data_;
};

#endif //__B_HPP__