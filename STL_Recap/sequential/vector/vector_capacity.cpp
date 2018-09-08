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
    std::vector<int> numbers = {1, 3, 4, 5};
    std::vector<Point> points;

    /* 1. size() -- returns the number of elements in a vector */
    std::cout << "size of numbers is: " << numbers.size() << std::endl;


    /* 2. capacity() -- returns the storage allocated in terms of no of objects */
    std::cout << "capacity before: " << numbers.capacity() << std::endl;

    numbers.push_back(7);
    std::cout << "capacity after: " << numbers.capacity() << std::endl;

    /* 3. max_size() -- returns the maximum number of object that the vector can hold */
    std::cout << "max size for int: " << numbers.max_size() << std::endl;
    std::cout << "max size for points: " << points.max_size() << std::endl;

    /* 4. resize() -- changes the size of the vector 
            - resize(n)
            - resize(n, value)

            if n < currentSize  --> extra elements will be destroyed
            if n > currentSize  --> extra elements are constructed till size 'n'
            if n > capacity     --> rellocation happens
    */

    numbers.resize(3);
    std::cout << "size after resize: " << numbers.size() << std::endl;

    numbers.resize(10, 999);
    std::cout << "size after resize: " << numbers.size() << std::endl;
    printSequentialContainer(numbers);

    points.resize(3);
    printSequentialContainer(points);

    Point center(2, 4);
    points.resize(4, center);
    printSequentialContainer(points);

    points.resize(3);
    std::cout << " --- n < currentSize " << std::endl;
    std::cout << "size & capacity of points " << points.size() << " " << points.capacity() << std::endl;

    /* 5. reserve() -- reserves the capacity to n */
    points.reserve(10);
    std::cout << "size & capacity of points " << points.size() << " " << points.capacity() << std::endl;

    /* 6. shrink_to_fit --- makes capacity equals to size*/
    points.shrink_to_fit();
    std::cout << "size & capacity of points " << points.size() << " " << points.capacity() << std::endl;

    /* 7. empty */
    std::cout << "isEmpty: " << (points.empty()? "true" : "false") << std::endl;

    return 0;
}
