#ifndef __StackD_WITH_DEFAULT_PARAMS_HPP__
#define __StackD_WITH_DEFAULT_PARAMS_HPP__
#include <cassert>
#include <iostream>

template<typename T, typename Container = std::vector<T>>
class StackD
{
    public:
        StackD();
        ~StackD();
        void push(const T& element);
        void pop();
        const T& top() const;
        bool empty();
        void displayContents(std::ostream&);
        friend std::ostream& operator<<(std::ostream& os, StackD<T, Container> &st)
        {
            st.displayContents(os);
        }
    private:
        Container elements_;
};

template<typename T, typename Container>
StackD<T, Container>::StackD() 
{
    std::cout << "StackD constructed: " << std::endl;
};

template<typename T, typename Container>
StackD<T, Container>::~StackD() 
{
    std::cout << "StackD destructed: " << std::endl;
};

template<typename T, typename Container>
bool StackD<T, Container>::empty()
{
    return elements_.empty();
}

template<typename T, typename Container>
void StackD<T, Container>::push(const T& element)
{
    elements_.push_back(element);
}

template<typename T, typename Container>
void StackD<T, Container>::pop()
{
    assert(!empty());
    elements_.pop_back();
}

template<typename T, typename Container>
const T& StackD<T,Container>::top() const
{
    assert(!empty());
    elements_.back();
}

template<typename T, typename Container>
void StackD<T, Container>::displayContents(std::ostream& os)
{
    for (auto iter = elements_.crbegin(); iter != elements_.crend(); ++iter)
        os << "(" << *iter << ")" << std::endl;
    
    os << std::endl;
};


#endif //__StackD_WITH_DEFAULT_PARAMS_HPP__