#ifndef __MY_CLASS_HPP__
#define __MY_CLASS_HPP__

class MyClass
{
    public:
        MyClass(int data = 0);
        ~MyClass();
        int getData();
    private:
        int data_;
};

#endif  //__MY_CLASS_HPP__