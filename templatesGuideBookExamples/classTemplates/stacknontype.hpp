#include <iostream>
#include <ostream>
#include <array>

template<typename T, std::size_t MaxSize>
class StackOne
{
    public:
        StackOne();
        ~StackOne();
        void push(const T& element);
        void pop();
        const T& top() const;
        bool empty() const;
        void print(std::ostream& os) const;
        std::size_t size() const;

        template<typename U, std::size_t SZ>
        friend std::ostream& operator<<(std::ostream& os, const StackOne<U, SZ>& stk);
        
    private:
        std::array<T, MaxSize> elements_;
        std::size_t numOfElements_;
};

template<typename T, std::size_t MaxSize>
StackOne<T, MaxSize>::StackOne():numOfElements_(0){}

template<typename T, std::size_t MaxSize>
StackOne<T, MaxSize>::~StackOne() {}

template<typename T, std::size_t MaxSize>
std::size_t StackOne<T, MaxSize>::size() const
{
    return numOfElements_;
}

template<typename T, std::size_t MaxSize>
bool StackOne<T, MaxSize>::empty() const
{
    return (numOfElements_ == 0);
}

template<typename T, std::size_t MaxSize>
void StackOne<T, MaxSize>::push(const T& element)
{
    if(size() < MaxSize)
    {
        elements_[numOfElements_++] = element;
    }
}

template<typename T, std::size_t MaxSize>
void StackOne<T, MaxSize>::pop()
{
    if(!empty())
    {
        --numOfElements_;
    }
}

template<typename T, std::size_t MaxSize>
const T& StackOne<T, MaxSize>::top() const
{
    if(!empty())
    {
        return elements_[numOfElements_ - 1];
    }
}

template<typename T, std::size_t MaxSize>
void StackOne<T, MaxSize>::print(std::ostream& os) const
{
    std::size_t index = size() - 1;
    for(; index > 0 ; --index)
    {
        os << "|" << elements_[index] << "|" << "\n";
    }
    os << "|" << elements_[index] << "|" << "\n";
}

template<typename U, std::size_t SZ>
std::ostream& operator<<(std::ostream& os, const StackOne<U, SZ>& stk)
{
    stk.print(os);
    return os;
}