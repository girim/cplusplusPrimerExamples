#include <iostream>
#include <typeinfo>

template<typename T>
T max(T lhs, T rhs)     //Call parameter by value
{
    std::cout << "Type is: " << typeid(T).name() << std::endl;
    return (rhs < lhs) ? lhs : rhs;
}

template<typename T1, typename T2>
void takeParameterByReference(const T1& byRefLhs, const T2& byRefRhs)
{
    std::cout << "[takeReferenceByReference] T1: " << typeid(T1).name() << std::endl;
    std::cout << "[takeReferenceByReference] T2: " << typeid(T2).name() << std::endl;
}

template<typename T1, typename T2>
void takeParameterByValue(T1 byValueLhs, T2 byValueRhs)
{
    std::cout << "[takeParameterByValue] T1: " << typeid(T1).name() << std::endl;
    std::cout << "[takeParameterByValue] T2: " << typeid(T2).name() << std::endl;
}

void test()
{
    std::cout << "test Function: "  << std::endl;
}

int main()
{
    std::string str1("c"), str2("c++");
    std::cout << ::max(1, 3) << "\n";
    std::cout << ::max(1.2, 3.4) << "\n";
    std::cout << ::max(8.9f, 1.2f) << "\n";
    std::cout << ::max(str1, str2) << "\n";

    /* call parameter by reference -- No trivial conversions allowed */
    int number_1 = 10, number_2 = 20;
    double fraction_1 = 11.22, fraction_2 = 44.55;
    const int& refToNumber_1 =  number_1;
    const int& refToNumber_2 =  number_2;
    const double& refToFraction_1 = fraction_1;
    const double& refToFraction_2 = fraction_2;
    int arrayOfNumbers [] = {1, 2, 3, 4};
    float arrayOfFractions [] = {1.1, 2.2, 3.3};

    takeParameterByReference(refToNumber_1, refToNumber_2);
    takeParameterByReference(refToFraction_1, refToFraction_2);
    takeParameterByReference(number_1, fraction_1);
    takeParameterByReference(arrayOfNumbers, arrayOfFractions); //Raw arrays remains same
    takeParameterByReference(test, test); //functions remains functions

    std::cout << "\n";
    takeParameterByValue(refToNumber_1, refToNumber_2);
    takeParameterByValue(refToFraction_1, refToFraction_2);
    takeParameterByValue(fraction_2, number_2);
    takeParameterByValue(arrayOfNumbers, arrayOfFractions);  //Raw arrays converts to pointers
    takeParameterByValue(test, test);  //function --> pointer to function

    //std::cout << ::max(number_1, fraction_1);
    std::cout << ::max(number_1, static_cast<int>(fraction_1)) << std::endl;
    std::cout << ::max<double>(number_1, fraction_2) << std::endl;
    
    return 0;
}
