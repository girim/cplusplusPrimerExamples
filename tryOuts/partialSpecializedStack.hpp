#ifndef __PARTIAL_SPECIALIZED_STACK__
#define __PARTAIL_SPECIALIZED_STACK__

#include <iostream>
#include <deque>
#include <cassert>

template<typename T>
class Stack<T*>
{
    public:
        Stack();
        ~Stack();
        void push(T* element);
        void pop();
        bool empty() const;
        const T* top() const;
        void displayContents(std::ostream& os);
        friend std::ostream& operator<<(std::ostream &os, Stack<T*>& st)
        {
            st.displayContents(os);
        }

    private:
        std::deque<T*> pointers_;
};

template<typename T>
Stack<T*>::Stack(){}

template<typename T>
Stack<T*>::~Stack(){}

template<typename T>
bool Stack<T*>::empty() const
{
    return pointers_.empty();
}

template<typename T>
void Stack<T*>::push(T* element)
{
    pointers_.push_back(element);
}

template<typename T>
void Stack<T*>::pop()
{
    assert(!empty());
    pointers_.pop_back();
}

template<typename T>
const T* Stack<T*>::top() const
{
    assert(!empty());
    return pointers_.back();
}

template<typename T>
void Stack<T*>::displayContents(std::ostream& os)
{
    for(auto iter = pointers_.crbegin(); iter != pointers_.crend(); ++iter)
        os << "{" << **iter << "}" << std::endl;

    os << std::endl;
}


#endif //__PARTAIL_SPECIALIZED_STACK__