#include <vector>
#include <ostream>

template<typename T>
class StackOne
{
    public:
        StackOne();
        StackOne(const T& element);
        ~StackOne();
        void push(const T& element);
        void pop();
        const T& top() const;
        bool empty() const;

        void print(std::ostream& os) const;

        /* 1st Way
        friend std::ostream& operator<<(std::ostream& os, const StackOne<T>& stk)
        {
            stk.print(os);
            return os;
        } */

        /* 2nd Way */
        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const StackOne<U>& stk);

    private:
        std::vector<T> elements_;
};

template<typename T>
StackOne<T>::StackOne() {}

template<typename T>
StackOne<T>::StackOne(const T& element) : elements_({element})
{

}

template<typename T>
StackOne<T>::~StackOne() {}

template<typename T>
bool StackOne<T>::empty() const
{
    return elements_.empty();
}

template<typename T>
void StackOne<T>::push(const T& element)
{
    elements_.push_back(element);
}

template<typename T>
void StackOne<T>::pop()
{
    if(!empty())
        elements_.pop_back();
}

template<typename T>
const T& StackOne<T>::top() const
{
    if(!empty())
        return elements_.back();
}

template<typename T>
void StackOne<T>::print(std::ostream& os) const
{
    std::cout << "Elements of Stack are: " << std::endl;
    for(auto iter = elements_.rbegin(); iter != elements_.rend(); ++iter)
    {
        os << "|" << *iter << "|" << "\n";
    }
}

template<typename U>
std::ostream& operator<<(std::ostream& os, const StackOne<U>& stk)
{
    stk.print(os);
    return os;
}