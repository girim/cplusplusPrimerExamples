#include <iostream>
#include <vector>
#include <array>
#include "point.hpp"

template<typename Container>
void printSequentialContainer(const Container& cont)
{
    std::cout << "[ ";
    auto last = cont.cend()-1;
    for(auto iter = cont.cbegin(); iter != cont.cend(); ++iter)
    {
        (iter == last) ? (std::cout <<  *iter) : (std::cout <<  *iter << ", ");
    }
    std::cout << " ]" << std::endl;
}

int main(int argc, char const *argv[])
{
    /* Vector construction */

    /* 1. default constructor */
    std::vector<int> numbers_0;
    std::vector<Point> points_1;

    /* 2. fill constructor */
    std::vector<int> numbers_1(3);
    std::vector<std::string> names_1(2);
    std::vector<std::string> names_2(2, "c++");

    printSequentialContainer(numbers_1);
    printSequentialContainer(names_1);
    printSequentialContainer(names_2);

    Point center, somePoint(3, 4);
    std::vector<Point> points_2(2);
    std::vector<Point> points_3(3, somePoint);

    printSequentialContainer(points_2);
    printSequentialContainer(points_3);

    /* 3. range constructor */
    std::array<double, 3> digits = {1.1, 2.2, 3.3};
    std::vector<double> digitsVector(std::begin(digits), std::end(digits));

    std::vector<Point> copyOfPoints_3(points_3.begin(), points_3.end());

    printSequentialContainer(digitsVector);
    printSequentialContainer(copyOfPoints_3);

    /* 4. copy constructor */
    std::vector<std::string> copyOfNumbers(names_2);
    std::vector<Point> copyOfPoints_2(points_2);

    printSequentialContainer(copyOfNumbers);
    printSequentialContainer(copyOfPoints_2);

    /* 5. move constructor */
    std::vector<Point> movedVector(std::move(copyOfPoints_2));
    printSequentialContainer(movedVector);
    printSequentialContainer(copyOfPoints_2);
    std::cout << "isEmpty: " << (copyOfPoints_2.empty() ? "true" : "false") << std::endl;

    /* 6. initializer list */
    std::vector<int> primes = {1, 3, 5, 7};
    std::vector<Point> points = {center};

    printSequentialContainer(primes);
    printSequentialContainer(points);

    std::initializer_list<Point> il = {center};

    return 0;
}




