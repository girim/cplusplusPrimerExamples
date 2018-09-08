#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

bool isDot(const char& ch)
{
    return (ch == '.');
}

struct hasOddNumber
{
    bool operator()(int number)
    {
        return !(number % 2 == 0);
    }
};

int main()
{
    std::string text{"This is the text of file.1"};
    std::vector<int> numbers{2, 4, 5, 6, 8};

    //Using built-in libray function
    auto iter = std::find_if(text.begin(), text.end(), isdigit);
    std::cout << "digit found is: " << *iter << std::endl;

    //Using the user-defined function
    auto it = std::find_if(text.begin(), text.end(), isDot);
    if (it != text.end()) 
    {
        std::cout << "Dot found in the text " << std::endl;
    }

    //Using function objects
    auto hasOddNum = std::find_if(numbers.begin(), numbers.end(), hasOddNumber{});
    std::cout << "has odd number: " << *hasOddNum << std::endl;

    //Using lambda expressions
    auto hasEvenNum = std::find_if(numbers.begin(), numbers.end(), [](const int& number){
        return ((number % 2 == 0) && (number > 5));
    });
    std::cout << "hasEvenNum : " << *hasEvenNum << std::endl;

    return 0;
}
