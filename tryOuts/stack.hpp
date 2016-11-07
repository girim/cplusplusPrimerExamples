#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <vector>
#include <cassert>

/* Forward declared the stack */
template<typename T> class Stack;
template<typename T> std::ostream& operator<<(std::ostream&, const Stack<T>& st);

template<typename T>
class Stack
{
    public:
        Stack();
        ~Stack();
        void push(const T& element);
        void pop();
        const T& top() const;
        void displayContents(std::ostream& os) const;
        bool empty();

        /* Below is the ordinary function */
        /* friend std::ostream& operator<<(std::ostream& os, const Stack<T>& st)
        {
            st.displayContents(os);
        } */
        
        /* Below declares a Non-Template friend */
        //friend std::ostream& operator<<(std::ostream& os, const Stack<T>& st);

        /* Below is the function template */
        /* template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const Stack<U>& st); */

        friend std::ostream& operator<< <T> (std::ostream& os, const Stack<T>& st); 


    private:
        std::vector<T> container_;
};

/* constructor */
template<typename T>
Stack<T>::Stack() { }

template<typename T>
Stack<T>::~Stack(){ }

template<typename T>
bool Stack<T>::empty()
{
    return container_.empty();
}
template<typename T>
void Stack<T>::push(const T& element)
{
    container_.push_back(element);
}

template<typename T>
void Stack<T>::pop()
{
    assert(!empty());
    container_.pop_back();
}

template<typename T>
const T& Stack<T>::top() const
{
    assert(!empty());
    return container_.back();
}

template<typename T>
void Stack<T>::displayContents(std::ostream& os) const
{
    for(auto iter = container_.crbegin(); iter != container_.crend(); ++iter)
        os << "|" << *iter << "|" << std::endl;

    os << std::endl;
}

/* template<typename U>
std::ostream& operator<<(std::ostream& os, const Stack<U>& st)
{
    st.displayContents(os);
} */

template<typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& st)
{
    st.displayContents(os);
}

#endif //__STACK_HPP__
