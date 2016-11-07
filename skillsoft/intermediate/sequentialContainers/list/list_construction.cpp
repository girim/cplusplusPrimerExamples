#include <list>
#include "../printContainerContents.hpp"
#include "../Plane.hpp"

int main()
{
    /* 1. default constructor */
    std::list<int> emptylist;

    /* 2. fill (n, value), (n) */
    std::list<double> ones(4, 1.0);
    printContainerContents(ones, "ones");

    std::list<int> zeros(4);
    printContainerContents(zeros, "zeros");
    
    /* 3. initializer_list */
    std::list<int> numbers({1,2,3,4});
    printContainerContents(numbers, "numbers");

    /* 4. Ranges */
    std::list<double> copyOfOnes(ones.begin(), ones.end());
    printContainerContents(copyOfOnes, "copyOfOnes");

    /* 5. copy-constructor */
    std::list<int> copyOfNumbers(numbers);
    printContainerContents(copyOfNumbers, "copyOfNumbers");

    /* 6. move-constructor */
    std::list<int> copyOfZeros(std::move(zeros));
    printContainerContents(copyOfZeros, "copyOfZeros");

    /* zeros will be empty as the contents are moved */
    printContainerContents(zeros, "zeros");

    Plane p1{}, p2{};
    std::list<Plane> planelist{p1, p2};
    std::list<Plane> planelist_1(std::move(planelist));

    return 0;
}