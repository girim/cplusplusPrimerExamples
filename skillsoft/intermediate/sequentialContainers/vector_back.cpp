#include <vector>
#include <string>
#include "printVectorContents.hpp"

int main()
{
    /* std::vector::back
        Returns a reference to the last element in the vector.
            reference back();
            const_reference back() const;
     */
    std::vector<std::string> airlines{"Lufthansa", "IndiGo", "JetAirways"};
    std::cout << "last airline in the list is: " << airlines.back() << std::endl;
    printVectorContents(airlines, "airlinesBefore");

    airlines.back() = "AirFrance";
    printVectorContents(airlines, "airlinesAfter");

    const std::vector<std::string> countries{"India", "US", "UK", "Russia"};
    std::cout << "last counrty in the list is : " << countries.back() << std::endl;
    printVectorContents(countries, "countriesBefore");

    //countries.back() = "Israle";  //Cannot replace as back returns const_reference here

    std::vector<float> floatNumbers;
    //std::cout << "Last entry in floatNumbers is : " << floatNumbers.back() << std::endl;
    /* Calling .back on empty vector causes undefined behaviour */

    return 0;
}