#ifndef __C_HPP__
#define __C_HPP__

class A;
class C
{
    public:
        C(int data = 0);
        ~C();
        int getData();
        
    private:
        int data_;
};

#endif //__C_HPP__
