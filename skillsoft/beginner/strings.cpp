#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    /* 9 ways of constructing a string */
    std::string str_0("Initial string");

    /* 1.default constructor   --> string()*/
    std::string str_1;

    /* 2.copy constructor      --> string(const string& str)*/
    std::string str_2(str_0);

    /* 3.substring constructor --> string(const string& str, size_t pos, size_t len = npos) */
    std::string str_3(str_2, 8, 3);
    std::string str_4(str_2, 8);

    const char* arrayOfStrings[] = {"c++", "javascript", "java"};
    const char first = *(*(arrayOfStrings + 1) + 0);
    std::cout << "first: " << first << std::endl;
    std::cout << "arrayOfStrings[0]: " << *(arrayOfStrings + 0) << std::endl;

    /* 4.from c-string  --> string(const char* s) */
    std::string str_5("Hello C++");

    /* 5.from buffer    --> string(const char* s, size_t n) */
    std::string str_6("Good and bad", 4);

    /* 6.fill constructor --> string(size_t n, char c) */
    std::string str_7(10, '*');

    /* 7.Range constructor --> string(begin, end)*/
    std::string str_8(str_5.begin(), str_5.end());
    std::string str_9(str_5.begin(), str_5.end()-4);

    /* 8.Initializer list --> string(std::initializer_list<char>) */
    std::initializer_list<char> listOfChars;
    listOfChars = {'a', 'e', 'i', 'o', 'u', 's'};
    std::string str_10(listOfChars);

    /* 9. move constructor */
    std::string str_11(std::move(str_0));

    std::cout << "value of str_0: " << str_0 << std::endl;
    std::cout << "value of str_1: " << str_1 << std::endl;
    std::cout << "value of str_2: " << str_2 << std::endl;
    std::cout << "value of str_3: " << str_3 << std::endl;
    std::cout << "value of str_4: " << str_4 << std::endl;
    std::cout << "value of str_5: " << str_5 << std::endl;
    std::cout << "value of str_6: " << str_6 << std::endl;
    std::cout << "value of str_7: " << str_7 << std::endl;
    std::cout << "value of str_8: " << str_8 << std::endl;
    std::cout << "value of str_9: " << str_9 << std::endl;
    std::cout << "value of str_10: " << str_10 << std::endl;
    std::cout << "value of str_11: " << str_11 << std::endl;
    std::cout << "value of str_0: " << str_0 << std::endl;

    return 0;
}