#include <vector>
#include "printVectorContents.hpp"
#include "Plane.hpp"

std::ostream& operator<<(std::ostream& os, const Plane& plane)
{
    os << "{ length: " << plane.getLength() <<  " width: " << plane.getWidth() \
        << " Area: " << plane.getAreaOfPlane() << " }";

    return os;
}

int main()
{
    std::vector<double> fractions;
    fractions.push_back(1.1);
    fractions.push_back(2.2);
    fractions.push_back(3.3);

    printVectorContents(fractions, "Fractions");

    //std::vector<const int> reverseNumbers;
    //reverseNumbers.push_back(4);
    //reverseNumbers.push_back(3);
    //reverseNumbers.at(0) = 2;   //Cannot modify as the value_type is 'const'

    const std::vector<float> evenNumbers{2, 4, 6, 8};
    //evenNumbers.push_back(10)   //Cannot modify as the vector itself is 'const'

    Plane p1{}, p2{}, p3{};
    std::vector<Plane> planelist;
    planelist.push_back(p1);
    planelist.push_back(p2);
    planelist.push_back(p3);
    printVectorContents(planelist, "planelist");

}