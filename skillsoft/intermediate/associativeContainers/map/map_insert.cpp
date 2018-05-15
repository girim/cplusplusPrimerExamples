#include <map>
#include <iostream>
#include "../printAssociativeContainers.hpp"

int main()
{
    /* 1.insert  */
    std::map<char, int> alphaNumeric;
    alphaNumeric.insert(std::pair<char, int>('a', 26));
    auto res = alphaNumeric.insert(std::pair<char, int>('d', 28));
    alphaNumeric.insert(std::pair<char, int>('c', 27));

    printAssociativeContainer(alphaNumeric, "alphaNumeric");
    std::cout << "{res.first->first: " << res.first->first << " ,res.first->second: " \
                << res.first->second << " },res.second: " << res.second << std::endl;

    res = alphaNumeric.insert(std::pair<char, int>('d', 28));
    std::cout << "{res.first->first: " << res.first->first << " ,res.first->second: " \
                << res.first->second << " },res.second: " << res.second << std::endl;

    /* 2. with hint (uses position) */
    std::map<char, int>::iterator iter  = alphaNumeric.begin();
    auto it = alphaNumeric.insert(iter, std::make_pair<char, int>('A', 23));
    std::cout << "it value is: first -> " << it->first  << " ,second -> " << it->second << std::endl;
    printAssociativeContainer(alphaNumeric, "alphaNumeric");

    /* Insert with same key will not update the corresponding value with new value */
    it = alphaNumeric.insert(iter, std::make_pair<char, int>('a', 34));
    std::cout << "it value is: first -> " << it->first  << " ,second -> " << it->second << std::endl;
    printAssociativeContainer(alphaNumeric, "alphaNumeric");

    /* 3. with Range */
    std::map<char, int> copyOfAlphaNumeric;
    copyOfAlphaNumeric.insert(++alphaNumeric.begin(), alphaNumeric.end());
    printAssociativeContainer(copyOfAlphaNumeric, "copyOfAlphaNumeric");\
    

    /* 4. initializer_list */
    std::map<int, std::string> spectrumList({{1, "Alpha"},{2, "Beta"},{3, "Gamma"}});
    printAssociativeContainer(spectrumList, "spectrumList");

    return 0;
}