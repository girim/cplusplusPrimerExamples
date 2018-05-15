#ifndef __STACK_AUTO_HPP__
#define __STACK_AUTO_HPP__

template<typename T, auto Maxsize>
class StackAuto
{
    public:
        using sizeType = decltype(Maxsize);
        StackAuto();
        ~StackAuto();
        void push(const T& element);
        void pop();
        const T& top() const;
        bool empty() const;
        sizeType size() const;
        void print(std::ostream& os) const;

        template<typename U, auto SZ>
        friend std::ostream& operator<<(std::ostream& os, const StackAuto<U,SZ)>& stk);
        
    private:
        sizeType numOfElements_;
        std::array<T, Maxsize> elements_;
};

template<typename T, auto Maxsize>
StackAuto<T, Maxsize>::StackAuto():numOfElements_(0){}

template<typename T, auto Maxsize>
StackAuto<T, Maxsize>::~StackAuto() {}

template<typename T, auto Maxsize>
bool StackAuto<T, Maxsize>::empty()const 
{
    return (numOfElements_ == 0);
}

template<typename T, auto Maxsize>
sizeType StackAuto<T, Maxsize>::size() const
{
    return numOfElements_;
}

template<typename T, auto Maxsize>
void StackAuto<T, Maxsize>::push(const T& element)
{
    if (size() < Maxsize)
    {
        elements_[numOfElements_++] = element;
    }
}

template<typename T, auto Maxsize>
void StackAuto<T, Maxsize>::pop()
{
    if(!empty())
        --numOfElements_;
}

template<typename T, auto Maxsize>
const T& StackAuto<T, Maxsize>::top() const
{
    if(!empty())
        return elements_[numOfElements_ - 1];
}

template<typename T, auto Maxsize>
void StackAuto<T, Maxsize>::print(std::ostream& os) const
{
    auto index = size() - 1;
    for(;index > 0; index--)
    {
        os << "{ " << elements_[index] << " }" << "\n";
    }
    os << "{ " << elements_[index] << " }" << "\n";
}

template<typename U, auto SZ>
friend std::ostream& operator<<(std::ostream& os, const StackAuto<U, SZ>& stk)
{
    stk.print(os);
    return os;
}

#endif // !__STACK_AUTO_HPP__
