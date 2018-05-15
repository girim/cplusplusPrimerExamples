#include <iostream>

/* 
Below function with default arguments creates a ambiguous call
long multiply(short x, short y, short z = 1)
{
    return (x * y * z);
} */

short multiply(short x, short y)
{
    return (x * y);
}

int multiply(int x, int y)
{
    return (x * y);
}

long multiply(long x, long y)
{
    return (x * y);
}

float multiply(float x, float y)
{
    return (x * y);
}

double multiply(double x, double y)
{
    return (x * y);
}

long multiply(short x, int y, long z)
{
    std::cout << "multiply[long(short, int, long)] is called: \n";
    return (x * y * z);
}

long multiply(int x, long y, short z)
{
    std::cout << "multiply[long(int, long, short)] is called: \n";
    return (x * y * z);
}

long multiply(long x, short y, int z)
{
    std::cout << "multiply[long(long, short, int)] is called: \n";
    return (x * y * z);
}

int main(int argc, char* argv[])
{
    short a = 1, b = 2;
    int c = 3, d = 4;
    long e = 23, f = 56;
    float g = 1.2F, h = 3.4F;
    double i = 122.434, j = 22323.2323;

    std::cout << "Result => short(short, short): " << multiply(a, b) << std::endl;
    std::cout << "Result => int(int, int): "       << multiply(c, d) << std::endl;
    std::cout << "Result => long(long, long): "    << multiply(e, f) << std::endl;
    std::cout << "Result => float(float, float): " << multiply(g, h) << std::endl;
    std::cout << "Result => double(double, double): " << multiply(i, j) << std::endl;

    std::cout << "Result => [long(long, short, int)]: " << multiply(e, a, d) << std::endl;
    std::cout << "Result => [long(int, long, short)]: " << multiply(d, f, b) << std::endl;
    std::cout << "Result => [long(short, int, long)]: " << multiply(b, d, f) << std::endl;

    return 0;
}