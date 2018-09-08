#ifndef __PRINT_ASSOCIATIVE_CONT_HPP__
#define __PRINT_ASSOCIATIVE_CONT_HPP__

template<typename Cont>
void printAssocContainer(const Cont& cont)
{
    if(cont.empty())
    {
        std::cout <<" [ ] " << "\n";
        return;
    }
    for(auto iter = cont.begin(); iter != cont.end(); ++iter)
    {
        std::cout << "[ Key: " << iter->first << " Value: " << iter->second << " ]\n";
    }
    std::cout << std::endl;
}


#endif // __PRINT_ASSOCIATIVE_CONT_HPP__