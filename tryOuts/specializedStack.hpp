#ifndef __SPECIALIZED_STACK__
#define __SPECIALIZED_STACK__

#include <deque>
#include <cassert>

template<>
class Stack<double>
{
    public:
        Stack();
        ~Stack();
        void push(const double &element);
        void pop();
        const double& top() const;
        void displayContents(std::ostream& os);

        friend std::ostream& operator<<(std::ostream& os, Stack<double>& st)
        {
            st.displayContents(os);
        }
        
        bool empty() const;

    private:
        std::deque<double> elementList_;
};

Stack<double>::Stack(){}

Stack<double>::~Stack(){}

bool Stack<double>::empty() const
{
    return elementList_.empty();
}

void Stack<double>::push(const double &element)
{
    elementList_.push_back(element);
}

void Stack<double>::pop()
{
    assert(!empty());
    elementList_.pop_back();
}

const double& Stack<double>::top() const
{
    assert(!empty());
    elementList_.back();
}

void Stack<double>::displayContents(std::ostream& os)
{
    for(auto iter = elementList_.crbegin(); iter != elementList_.crend(); ++iter)
        os << "||" << *iter << "||" << std::endl;

    os << std::endl;
}

#endif //__SPECIALIZED_STACK__