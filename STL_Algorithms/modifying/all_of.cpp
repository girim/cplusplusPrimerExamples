#include <algorithm>
#include <iostream>
#include "../point.hpp"
#include <set>
#include <list>



int main(int argc, char const *argv[])
{
    /* Returns 'true' if all of the elements passes truth test */
    std::set<unsigned> numbers = {3, 5, 7, 9, 1, 11};

    bool result = std::all_of(numbers.begin(), numbers.end(), [](const unsigned& number){
        return (number % 2 != 0);
    });

    std::cout <<  "All are primes ....? "  << std::boolalpha << result << "\n";

    numbers.emplace(2);
    result = std::all_of(numbers.begin(), numbers.end(), [](const unsigned& number){
        return (number % 2 == 0);
    });

    std::cout <<  "All are non-primes ....? "  << std::boolalpha << result << "\n";

    Point pt0{}, pt1{1}, pt2{2}, pt3{3, 5};
    std::list<Point> points = {pt0, pt1, pt2}; //, pt3};
    result = std::all_of(points.begin(), points.end(), [](const Point& point){
            return (point.getX() == point.getY());
    });

    std::cout << "All the points in list are having x == y? "<< std::boolalpha << result << "\n";

    return 0;
}
