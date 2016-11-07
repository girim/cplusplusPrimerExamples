#ifndef __CLASS_TEMPLATE_ARGS_DEDUCTION_HPP__
#define __CLASS_TEMPLATE_ARGS_DEDUCTION_HPP__

#include <iostream>

template<typename T>
class StackG
{
    public:
        StackG() = default;
        StackG(const T& element);
        ~StackG();
        void push(const T& element);
        void pop();
        const T& top() const;
        bool empty() const;

        void displayContents(std::ostream& os);

        friend std::ostream& operator<<(std::ostream& os, const StackG& st)
        {
            st.displayContents(os);
        }

    private:
        std::vector<T> elements_;
};

template<typename T>
StackG<T>::StackG(const T& element) : elements_({element}) {}

template<typename T>
StackG<T>::~StackG() {}

template<typename T>
bool StackG<T>::empty() const
{
    return elements_.empty();
}

template<typename T>
void StackG<T>::push(const T& element)
{
    elements_.push_back(element);
}

template<typename T>
void StackG<T>::pop()
{
    assert(!empty());
    elements_.pop_back();
}

template<typename T>
const T& StackG<T>::top() const
{
    assert(!empty());
    return elements_.back();
}

#endif // !__CLASS_TEMPLATE_ARGS_DEDUCTION_HPP__