#include <iostream>

void testFunction(int passByValue)
{
    std::cout << "passByValue: " << passByValue << " Address: <" << &passByValue << ">" << std::endl;
    passByValue = 40;
}

void testFunction(short &passByRef)
{
    std::cout << "passByRef: " << passByRef << " Address: <" << &passByRef << ">" << std::endl;
    passByRef = 80;
}

void testFunction(double *passByAddress)
{
    std::cout << "passByAddress: " << passByAddress << " Address: " << &passByAddress << std::endl;
    *passByAddress = 90;
}

void addingNewFunction()
{
    std::cout << "this is the new function: " << std::endl;
}

void someTestFunction()
{
    std::cout << "someTestFunction" << std::endl;
}

void testFunctionTwo()
{
    //do nothing
    std::cout << "Inside testFunctionTwo...." << std::endl;
}


int main(int argc, char* argv[])
{
    int passByValue = 0;
    std::cout << "Address of passByValue[main]: " << &passByValue << std::endl;
    testFunction(passByValue);
    std::cout << "Value of passByValue: " << passByValue << "\n";

    short passByRef = 1;
    std::cout << "Address of passByRef[main]: " << &passByRef << std::endl;
    testFunction(passByRef);
    std::cout << "Value of passByRef: " << passByRef << "\n";

    double passByAddress  = 1.23;
    std::cout << "Value of passbyAddress before function call: " << &passByAddress << "\n";
    testFunction(&passByAddress);
    std::cout << "Value of passByAddress after function call: " << passByAddress << "\n";

    double *ptrToPassByAddress = &passByAddress;
    testFunction(ptrToPassByAddress);
    std::cout << "address of ptrToPassAddress: " << &ptrToPassByAddress << "\n";

    return 0;
}