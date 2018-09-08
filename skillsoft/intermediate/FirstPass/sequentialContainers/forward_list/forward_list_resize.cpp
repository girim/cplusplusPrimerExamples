#include <forward_list>
#include "../printContainerContents.hpp"

int main()
{
    std::forward_list<double> fractions{1.1, 1.2, 1.3, 1.4};
    printContainerContents(fractions, "fractions");

    /* resize(n) */
    fractions.resize(2);
    printContainerContents(fractions, "fractions");

    /* resize(n, val) */
    fractions.resize(5, 222);
    printContainerContents(fractions, "fractions");

    return 0;
}