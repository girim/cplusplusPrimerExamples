#ifndef __BAR_HPP__
#define __BAR_HPP__

class Foo;
class Bar
{
    public:
        Bar(double data = 0);
        ~Bar();
        double getData();
        void combineDataFromFooAndBar(Foo &foo);

    private:
        double data_;
};

#endif //__BAR_HPP__