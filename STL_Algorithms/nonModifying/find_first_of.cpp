#include <iostream>
#include <algorithm>
#include <vector>
#include "../point.hpp"
#include <list>

int main(int argc, char const *argv[])
{
    std::vector<std::string> countries  = {"India", "Austria", "Poland", "Germany"};
    std::vector<std::string> toSearch = {"Czech", "Poland", "Slovakia"};

    auto iter  = std::find_first_of(countries.begin(), countries.end(), toSearch.begin(), toSearch.end());

    if(iter != countries.end())
    {
        std::cout << "Item " << *iter << " found at position: " << (iter - countries.begin()) << "\n";
    }

    return 0;
}
