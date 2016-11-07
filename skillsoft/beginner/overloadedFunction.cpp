#include <iostream>

/* overloaded funtions */
short  multiply(short x, short y) { return (x * y); }
int    multiply(int x, int y) { return (x * y); }
long   multiply(long x, long y) { return (x * y); }
float  multiply(float x, float y) { return (x * y); }
double multiply(double x, double y) { return (x * y);}

int main()
{
    short sx = 5, sy = 7;
    int ix = 6, iy = 8;
    long lx = 3, ly = 4;
    float fx = 1.2, fy = 3.4;
    double dx = 4.55, dy = 6.77;

    std::cout << "short  (short, short)   : " << multiply(sx, sy) << std::endl;
    std::cout << "int    (int, int)       : " << multiply(ix, iy) << std::endl;
    std::cout << "long   (long, long)     : " << multiply(lx, ly) << std::endl;
    std::cout << "float  (float, float)   : " << multiply(fx, fy) << std::endl;
    std::cout << "double (double, double) : " << multiply(dx, dy) << std::endl;

    return 0;
}


