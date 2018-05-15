#include <iostream>
#include <bitset>

int main(int argc, char* argv[])
{
    /* int intType = 3;
    short int shortType = 4;
    signed short int sShorType = 2323; */
    std::string units = " Bytes";

    std::cout << "size of (int): " << sizeof(int) << units << std::endl;
    std::cout << "size of (short int): " << sizeof(short int) << units << std::endl;
    std::cout << "size of (signed short int): " << sizeof(signed short int) << units << std::endl;

    return 0;
}