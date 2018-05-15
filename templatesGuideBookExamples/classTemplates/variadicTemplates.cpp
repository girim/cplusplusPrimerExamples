#include <iostream>
#include <string>

void print() {
    std::cout << "empty print called" << std::endl;
}

template<typename T, typename... Types>
void print(T firstArg, Types... args)
{
    std::cout << "firstArg: "  << firstArg << "\n";
    print(args...);
}

template<typename T>
void print_1(T arg)
{
    std::cout << "arg: " << arg << "\n";
}

template<typename T, typename... Types>
void print_1(T firstArg, Types... args)
{
    std::cout << "firstArg: " << firstArg << "\n";
    print_1(firstArg);
    print_1(args...);
}

int main(int argc, char* argv[])
{
    std::string str = "c++";
    //print(100, "Hello", 1.3f, str);

    print_1(12, "Hello", 1.2f, str);

    return 0;
}