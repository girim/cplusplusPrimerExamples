#include <iostream>

void someFunction(int passByValue, int *passByPointer, int* &passByReference)
{
    std::cout << "Value of passByValue:      " << passByValue << std::endl;
    std::cout << "Address of passByValue:    " << &passByValue << std::endl;
    std::cout << std::endl;

    std::cout << "Value of passByPointer:    " << *passByPointer << std::endl;
    std::cout << "Address of variable:       " << passByPointer << std::endl;
    std::cout << "Address of &passByPointer: " << &passByPointer << std::endl;
    std::cout << std::endl;

    std::cout << "Value of passByReference:  " << *passByReference << std::endl;
    std::cout << "Address of variable:       " << passByReference << std::endl;
    std::cout << "Address of pointer is :    " << &passByReference << std::endl;
    std::cout << std::endl;
}

int main()
{
    int variable = 4;
    int *ptrToVariable = &variable;

    /* Reference to the Pointer itself */
    int* &refToPtrToVariable = ptrToVariable;


    std::cout << "Value of variable:         " << variable << std::endl;
    std::cout << "Address of variable:       " << ptrToVariable << std::endl;
    std::cout << "Address of the Pointer:    " << &ptrToVariable << std::endl;
    std::cout << "Address of refToPtr:       " << &refToPtrToVariable << std::endl;
    std::cout << std::endl;

    someFunction(variable, ptrToVariable, refToPtrToVariable);

    return 0;
}