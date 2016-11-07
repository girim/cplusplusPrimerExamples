#include <vector>
#include <string>
#include "Plane.hpp"

int main()
{
    std::vector<int> evenNumbers{2,4,6,8,10};
    std::cout << "size of vector evenNumbers is : " << evenNumbers.size() << std::endl;
    std::cout << "capcity of the vector evenNumbers is : " << evenNumbers.capacity() << std::endl;
    
    evenNumbers.push_back(12);
    evenNumbers.push_back(14);
    std::cout << "size of vector evenNumbers is : " << evenNumbers.size() << std::endl;
    std::cout << "capcity of the vector evenNumbers is : " << evenNumbers.capacity() << std::endl;

    evenNumbers.push_back(16);
    evenNumbers.push_back(16);
    evenNumbers.push_back(16);
    evenNumbers.push_back(16);
    std::cout << "size of vector evenNumbers is : " << evenNumbers.size() << std::endl;
    std::cout << "capcity of the vector evenNumbers is : " << evenNumbers.capacity() << std::endl;
    
    evenNumbers.insert(evenNumbers.begin(), 25, 0);
    std::cout << "size of vector evenNumbers is : " << evenNumbers.size() << std::endl;
    std::cout << "capcity of the vector evenNumbers is : " << evenNumbers.capacity() << std::endl;

    Plane p1{}, p2{}, p3{};
    std::vector<Plane> planeList{p1, p2, p3};
    std::cout << "size of planelist: " << planeList.size() << std::endl;
    std::cout << "capacity of planelist: " << planeList.capacity() << std::endl;

    planeList.emplace_back();
    std::cout << "size of planelist: " << planeList.size() << std::endl;
    std::cout << "capacity of planelist: " << planeList.capacity() << std::endl;
    
    return 0;
}