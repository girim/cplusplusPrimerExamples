#include "stack_1.hpp"
#include <deque>
#include <string>

template<>
class StackOne<std::string>
{
    public:
        StackOne();
        ~StackOne();
        void push(const std::string& str);
        void pop();
        const std::string& top() const;
        bool empty() const;
        void print(std::ostream& os) const;

        friend std::ostream& operator<<(std::ostream& os, StackOne<std::string> strStk)
        {
            strStk.print(os);
            return os;
        }
    private:
        std::deque<std::string> elements_;
};

StackOne<std::string>::StackOne(){};

StackOne<std::string>::~StackOne(){};

void StackOne<std::string>::push(const std::string& element)
{
    elements_.push_back(element);
}

bool StackOne<std::string>::empty() const
{
    return elements_.empty();
}

void StackOne<std::string>::pop()
{
    if(!empty())
    {
        return elements_.pop_back();
    }
}

const std::string& StackOne<std::string>::top() const
{
    if(!empty())
        return elements_.back();
}

void StackOne<std::string>::print(std::ostream& os) const
{
    os << "Element of stringStack are: " << "\n";
    for(auto iter = elements_.rbegin(); iter != elements_.rend(); ++iter)
    {
        os << "string: | " << *iter << " |" << "\n";
    }
}
