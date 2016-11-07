#include <vector>
#include <cassert>

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

        friend std::ostream& operator<<(std::ostream& os, const Stack<T>& st)
        {
            st.displayContents(os);
        }
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