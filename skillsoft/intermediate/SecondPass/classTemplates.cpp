#include <iostream>
#include <vector>
#include "../../point.hpp"

template <class T>
class Stack
{
    public:
        explicit Stack();
        ~Stack();

        void push(const T& element);
        void pop();
        T top() const;
        void printStack() const;

    private:
        std::vector<T> elements_;
};

template<class T>
Stack<T>::Stack() {};

template<class T>
Stack<T>::~Stack() {};

template<class T>
void Stack<T>::push(const T& element)
{
    elements_.push_back(element);
}

template<class T>
void Stack<T>::pop()
{
    if(elements_.empty())
    {
        throw std::out_of_range("Stack<>::pop : empty stack");
    }
    elements_.pop_back();
}

template<class T>
T Stack<T>::top() const
{
    if(elements_.empty())
    {
        throw std::out_of_range("Stack<>::top : empty stack");
    }
    return elements_.back();
}

template<class T>
void Stack<T>::printStack() const
{
    if(!elements_.empty())
    {
        for(auto iter = elements_.rbegin(); iter != elements_.rend(); ++iter)
        {
            std::cout << "| " << *iter << " |" << "\n";
        }
        std::cout << "------" << "\n";
    }
}

int main(int argc, char const *argv[])
{
    Stack<int> intStack{};
    intStack.push(10);
    intStack.push(20);

    intStack.printStack();
    intStack.push(30);
    intStack.printStack();

    intStack.pop();
    intStack.printStack();

    Stack<std::string> strStack{};
    strStack.push("C");
    strStack.push("C++");
    strStack.push("JavaScript");

    strStack.printStack();

    Stack<Point> pointsStack{};
    Point pt0{}, pt1{1}, pt2{2};
    pointsStack.push(pt0);
    pointsStack.push(pt1);
    pointsStack.push(pt2);
    pointsStack.printStack();

    Stack<double> dStack{};

    try
    {
        dStack.top();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    dStack.push(2.0);
    dStack.push(5.6);
    dStack.printStack();

    return 0;
}
