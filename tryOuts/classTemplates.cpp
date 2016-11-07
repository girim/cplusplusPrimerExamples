#include <iostream>
#include <string>
#include <deque>
#include "stack.hpp"
#include "specializedStack.hpp"
#include "partialSpecializedStack.hpp"
#include "partialSpecializationWithMultiParams.hpp"
#include "stackWithDefaultParams.hpp"
#include "classTemplateArgumentDeduction.hpp"

template<typename T1, typename T2>
using IntFloat = MyClass<T1, T2>;

template<typename T>
using TwiceDouble = MyClass<T,T>;

int main()
{
    /* Uses template Stack */
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.push(40);
    intStack.pop();
    std::cout << intStack;

    /* Uses template Stack */
    Stack<std::string> strStack;
    strStack.push("Hi");
    strStack.push("Hello");
    strStack.push("Hola");
    std::cout << strStack;
    strStack.pop();
    strStack.pop();

    /* Uses Specialized Stack */
    Stack<double> doubleElements;
    doubleElements.push(1.2);
    doubleElements.push(2.3);
    doubleElements.push(3.4);
    std::cout << doubleElements;
    
    /* Uses Partialy Specialized Stack */
    float fVar1 = 0.1, fVar2 = 1.2, fVar3 = 2.3;
    float *fp1, *fp2, *fp3;
    fp1 = &fVar1, fp2 = &fVar2, fp3 = &fVar3;
    
    Stack<float*> floatPointers;
    floatPointers.push(fp1);
    floatPointers.push(fp2);
    floatPointers.push(fp3);
    std::cout << floatPointers;
    floatPointers.pop();
    std::cout << floatPointers;

    int number1 = 1, number2 = 2, number3 = 3;
    int &refToNumber1 = number1;
    int &refToNumber2 = number2;
    int &refToNumber3 = number3; 
    //Stack<int&> refNumbers;

    IntFloat<int, float> intFloat;
    TwiceDouble<double> doubleDouble;
    MyClass<int, char> intChar;
    MyClass<float*, float*> floats;
    MyClass<int*, float*> intFloatPointers;

    std::cout << "intFloat: " << intFloat.getName() << std::endl;
    std::cout << "doubleDouble: " << doubleDouble.getName() << std::endl;
    std::cout << "intChar: " << intChar.getName() << std::endl;
    std::cout << "floatPointers: " << floats.getName() << std::endl;
    std::cout << "intFloatPointers: " << intFloatPointers.getName() << std::endl;

    StackD<int> intStackD;
    intStackD.push(01);
    intStackD.push(02);
    intStackD.push(03);
    intStackD.push(04);

    std::cout <<intStackD;

    /* Renaming the type */
    typedef StackD<double, std::deque<double>> DoubleStackD;
    DoubleStackD doubleStackD;
    
    doubleStackD.push(4.4);
    doubleStackD.push(4.3);
    doubleStackD.push(4.2);
    doubleStackD.push(4.1);

    std::cout << doubleStackD;

    return 0;
}
