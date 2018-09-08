#include <vector>
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
    std::vector<double> digits = {1.1, 2.2, 3.3, 4.4};

    /* 1. using [] operator -- returns lvalue- reference to element */
    std::cout << "digit at position 1 is: " << digits[1] << std::endl;
    printSequentialContainer(digits);
    
    digits[2] = 5.5;
    printSequentialContainer(digits);

    Point center(1, 2);
    std::vector<Point> points(3, center);
    printSequentialContainer(points);

    points[0].setX(0); 
    points[0].setY(0); 
    printSequentialContainer(points);


    /* 2. using at() --> returns lvalue- reference to element 
        at throws out_of_range error */
    digits.at(3) = 8.8;
    printSequentialContainer(digits);
    
    try
    {
        digits.at(5);
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }

    /* 3. front -- returns references to first element in the vector */
    digits.front() = 0.0;
    printSequentialContainer(digits);

    /* 4. back -- retursn references to the last element in the vector */
    digits.back() = 9.9;    
    printSequentialContainer(digits);

    /* 5. data -- returns raw pointer to the first element of the vector  */
    Point *ptr = points.data();
    std::cout << "x is: " << ptr->getX() << std::endl;
    std::cout << "y is: " << ptr->getY() << std::endl;

    ptr->setX(4);
    ptr->setY(4);

    printSequentialContainer(points);

    ++ptr;
    std::cout << "x is: " << ptr->getX() << std::endl;
    std::cout << "y is: " << ptr->getY() << std::endl;

    return 0;
}
