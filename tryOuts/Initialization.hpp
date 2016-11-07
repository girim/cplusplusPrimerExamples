#ifndef __INITIALIZATION__
#define __INITIALIZATION__

#include <iostream>

class Test
{
    public:
        Test() = default;
        Test(int data);
        /* Test(Test& test); */
        ~Test();
        int getData() const;
        friend std::ostream& operator<<(std::ostream& os, const Test& test)
        {
            os << "[" << test.getData() << "]" << std::endl;
        }

    private:
        int data_;
};

#endif //__INITIALIZATION__