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
    std::vector<double> fractions{1.9, 2.8, 3.7, 4.6, 5.5, 6.4, 7.3, 8.2, 9.1};
    printVectorContents(fractions, "fractions_1");

    //1. erase(position(iterator))
    fractions.erase(fractions.end()-1);
    printVectorContents(fractions, "fractions_2");

    //2. erase([first, last))
    auto iter = fractions.erase(fractions.begin()+2, fractions.end()-2);
    printVectorContents(fractions, "fractions_3");
    
    std::cout <<"iterator points to : " << *iter << std::endl; 

    return 0;
}