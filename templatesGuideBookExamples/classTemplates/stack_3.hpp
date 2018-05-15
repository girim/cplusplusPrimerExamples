#include <vector>
#include <iostream>
#include <ostream>

template<typename T, typename Container = std::vector<T> >
class StackTwo
{
    public:
        StackTwo();
        ~StackTwo();
        void push(const T& element);
        void pop();
        const T& top() const;
        bool empty() const;
        void print(std::ostream&) const;

        template<typename U, typename C>
        friend std::ostream& operator<<(std::ostream& os, const StackTwo<U, C>& stk);

    private:
        Container elements_;
};

template<typename T, typename Container>
StackTwo<T, Container>::StackTwo() {}

template<typename T, typename Container>
StackTwo<T, Container>::~StackTwo() {}

template<typename T, typename Container>
bool StackTwo<T, Container>::empty() const
{
    return elements_.empty();
}

template<typename T, typename Container>
void StackTwo<T, Container>::push(const T& element)
{
    elements_.push_back(element);
}

template<typename T, typename Container>
void StackTwo<T, Container>::pop()
{
    if(!empty())
    {
        return elements_.pop_back();
    }
}

template<typename T, typename Container>
const T& StackTwo<T, Container>::top() const
{
    if(!empty())
        return elements_.back();
}

template<typename T, typename Container>
void StackTwo<T, Container>::print(std::ostream& os) const 
{
    for(auto iter = elements_.rbegin(); iter!= elements_.rend(); ++iter)
    {
        os << "| " << *iter << "|" << "\n";
    }
}

template<typename U, typename C>
std::ostream& operator<<(std::ostream& os, const StackTwo<U, C>& stk)
{
    stk.print(os);
    return os;
}