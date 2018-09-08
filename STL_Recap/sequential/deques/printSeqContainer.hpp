#ifndef __PRINT_SEQ_CONTAINER_HPP__
#define __PRINT_SEQ_CONTAINER_HPP__

template<typename Container>
void printSequentialContainer(const Container& cont)
{
    std::cout << "[ ";
    auto last = cont.cend()-1;
    for(auto iter = cont.cbegin(); iter != cont.cend(); ++iter)
    {
        (iter == last) ? (std::cout <<  *iter) : (std::cout <<  *iter << ", ");
    }
    std::cout << " ]" << std::endl;
}

#endif