#ifndef __PRINT_ASSOCIATIVE_CONT_HPP__
#define __PRINT_ASSOCIATIVE_CONT_HPP__

template<typename Cont>
void printAssocContainer(const Cont& cont)
{
    if(cont.empty())
    {
        std::cout <<"[ empty ]" << "\n";
        return;
    }
    for(auto iter = cont.begin(); iter != cont.end(); ++iter)
    {
        std::cout << "[ Key: " << iter->first << " Value: " << iter->second << " ]\n";
    }
    std::cout << std::endl;
}

template<typename T>
void printSizeOfEachBuckets(const T& assocContainer)
{
    /* bucket size --> gives size of each bucket */
    for (size_t bucket = 0; bucket < assocContainer.bucket_count(); ++bucket)
    {
        std::cout << "Size of bucket #" << bucket << "  is : " << assocContainer.bucket_size(bucket) << "\n";
    }
    std::cout << "\n";
}

template<typename T>
void printTheItemsInEachBuckets(const T& assocContainer)
{
    for(auto iter = assocContainer.cbegin(); iter != assocContainer.cend(); ++iter)
    {
        std::cout << "Item " << iter->second << " is in bucket #" << assocContainer.bucket(iter->first) << "\n"; 
    }
    std::cout << "\n";
}


#endif // __PRINT_ASSOCIATIVE_CONT_HPP__
