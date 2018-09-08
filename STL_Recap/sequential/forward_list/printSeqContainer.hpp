#ifndef __PRINT_SEQ_CONTAINER_HPP__
#define __PRINT_SEQ_CONTAINER_HPP__

#include <forward_list>
#include <iterator>

template<typename Container>
void printSequentialContainer(const Container& cont)
{
    std::cout << "[ ";
    auto last = --cont.cend();
    for(auto iter = cont.cbegin(); iter != cont.cend(); ++iter)
    {
        (iter == last) ? (std::cout <<  *iter) : (std::cout <<  *iter << ", ");
    }
    std::cout << " ]" << std::endl;
}

/* partially overloaded */
template<typename T>
void printSequentialContainer(const std::forward_list<T>& list)
{
    std::cout << "[ ";
    if(!list.empty())
    {
        auto size = std::distance(list.begin(), list.end());
        auto iter = list.begin();

        int count = 0;

        while(count < (size - 1))
        {
            std::cout << *iter++ << ", ";
            ++count;
        }
        std::cout << *iter;
    }
    std::cout << " ]" << std::endl;
}
#endif
