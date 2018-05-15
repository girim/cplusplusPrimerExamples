#include <ostream>
#include <iostream>
#include "stack_2.hpp"

template<typename T>
class StackOne<T*>
{
    public:
        StackOne();
        ~StackOne();
        void push(T* element);
        T* pop();
        T* top() const;
        bool empty() const;
        void print(std::ostream& os) const;

        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const StackOne<U*>& ptrStk);

    private:
        std::vector<T*> pointers_;
};

template<typename T>
StackOne<T*>::StackOne() {};

template<typename T>
StackOne<T*>::~StackOne() {};

template<typename T>
void StackOne<T*>::push(T* pointer)
{
    pointers_.push_back(pointer);
}

template<typename T>
bool StackOne<T*>::empty() const
{
    return pointers_.empty();
}

template<typename T>
T* StackOne<T*>::pop() 
{
    T * ptr = nullptr;
    if(!empty())
    {
        ptr = pointers_.back();
        pointers_.pop_back();
    }
    return ptr;
}

template<typename T>
T* StackOne<T*>::top() const
{
    if(!empty())
        return pointers_.back();
}

template<typename T>
void StackOne<T*>::print(std::ostream& os) const
{
    os << "Elements of pointers is: " << "\n";
    for(auto iter = pointers_.rbegin(); iter != pointers_.rend(); ++iter)
    {
        os << "| " << *(*iter) << " |" << "\n";
    }
}

template<typename U>
std::ostream& operator<<(std::ostream& os, const StackOne<U*>& ptrStk)
{
    ptrStk.print(os);
    return os;
}