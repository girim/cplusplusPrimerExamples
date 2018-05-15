#include <iostream>
#include <deque>
#include "stackPartialSpec.hpp"
#include "stack_3.hpp"

int main(int argc, char* argv[])
{
    StackOne<int> intStackone;
    intStackone.push(10);
    intStackone.push(20);
    intStackone.push(30);
    intStackone.push(40);
    std::cout << intStackone << "\n";
    //intStackone.print();
    intStackone.pop();
    intStackone.pop();
    //intStackone.print();
    std::cout << "top element is: " << intStackone.top() << "\n";

    StackOne<std::string> stringStackone;
    stringStackone.push("C++");
    stringStackone.push("python");
    stringStackone.push("javaScript");
    //stringStackone.print();
    std::cout << stringStackone << "\n";

    using StackOneForDouble = StackOne<double>;
    StackOneForDouble doubleStack;
    doubleStack.push(1.22);
    doubleStack.push(3.22);
    //doubleStack.print();
    std::cout << doubleStack << "\n";

    int x = 1000, y = 2000, z = 3000;
    int *intPtr1 = &x;
    int *intPtr2 = &y;
    int *intPtr3 = &z;

    StackOne<int*> intPtrStack;
    intPtrStack.push(intPtr1);
    intPtrStack.push(intPtr3);
    intPtrStack.push(intPtr2);

    std::cout << intPtrStack << "\n";


    StackTwo<int, std::deque<int>>  intStackTwo;
    intStackTwo.push(1234);
    intStackTwo.push(4757);
    std::cout << intStackTwo <<  "\n";

    //StackOne stk = 0;


    return 0;
}
