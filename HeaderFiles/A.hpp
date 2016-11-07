#ifndef __A_HPP__
#define __A_HPP__
#include <iostream>
#include "B.hpp"

//class B;
class A
{
    public:
        A(B &refToB, B *ptrToB = nullptr, int data = 0);    
        ~A();
        int getData();
        /* A contains B must include B.hpp*/
        //B someFunc(B b);

        /* A has reference to B only forward declaration of A is sufficient*/
        B& someFunc(B &b);

        /* A has a pointer to B only forward declaration of A is sufficient*/
        B* someFunc(B *b);

        /* Adding class C as a friend */
        friend class C;

    private:
        B &refToB_;
        B *ptrToB_;
        B b_;
        int data_;
};

#endif //__A_HPP__