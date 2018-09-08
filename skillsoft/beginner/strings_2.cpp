#include <iostream>
#include <string>
#define EOL "\n"

int main(int argc, char const *argv[])
{
    std::string str("some text here");

    std::cout << "length of str: " << str.length() << EOL;
    std::cout << "size of str: " << str.size() << EOL;
    std::cout << "capacity of str: " << str.capacity() << EOL;
    std::cout << "max_size of str: " << str.max_size() << EOL;

    str.resize(20, '*');
    std::cout << "size of str '" << str << " 'post resize: " << str.length() << EOL;
    str.resize(14);
    std::cout << "size of str '" << str << " 'post resize: " << str.length() << EOL;

    str.reserve(25);  //to change the capacity
    std::cout << "capacity of str: " << str.capacity() << EOL;

    str.reserve(5);  //to change the capacity
    std::cout << "capacity of str: " << str.capacity() << EOL;

    str.shrink_to_fit();
    std::cout << "capacity of str: " << str.capacity() << EOL;
    std::cout << "size of str: " << str.size() << EOL;

    str.clear();
    std::cout << "size of str post clear: " << str.size() << EOL;

    std::cout << "is empty: " << str.empty() << EOL;



    return 0;
}
