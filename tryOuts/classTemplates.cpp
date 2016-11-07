#include <iostream>
#include <string>
#include "stack.hpp"
#include "specializedStack.hpp"
#include "partialSpecializedStack.hpp"

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

    return 0;
}
