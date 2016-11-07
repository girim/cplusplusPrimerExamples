#include <iostream>
#include <string>
#include "stack.hpp"

int main()
{
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.push(40);
    intStack.pop();
    std::cout << intStack;

    Stack<std::string> strStack;
    strStack.push("Hi");
    strStack.push("Hello");
    strStack.push("Hola");
    std::cout << strStack;
    strStack.pop();
    strStack.pop();
    
    float fVar1 = 0.1, fVar2 = 1.2, fVar3 = 2.3;
    float *fp1, *fp2, *fp3;
    fp1 = &fVar1, fp2 = &fVar2, fp3 = &fVar3;

    Stack<float *> floatPointers;
    floatPointers.push(fp1);
    floatPointers.push(fp2);
    floatPointers.push(fp3);

    return 0;
}
