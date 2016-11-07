#include "StrVector.hpp"

void StrVector::checkAndAllocate()
{
    std::cout << "checkAndAllocate: size: = " << size() << " capacity: = " << capacity() << std::endl;
    if(size() == capacity())
    {
        reallocate();
    }
}

void StrVector::free()
{
    std::cout << "free(): " << std::endl;
    if(element_)
    {
        for (auto ptr = ptrToFirstFree_; ptr != element_;)
        {
            customAllocator_.destroy(--ptr);
        }
        customAllocator_.deallocate(element_, (cap_ - element_));
    }
}

void StrVector::reallocate()
{
    std::cout << "reallocating locations.... " << std::endl;
    std::size_t  newCapacity = size() ? size() * 2 : 4;
    auto newData = customAllocator_.allocate(newCapacity);

    auto dest = newData;
    auto ele = element_;

    //std::cout <<"Size is : " << size() << std::endl;
    for(std::size_t index = 0; index < size(); index++)
    {
        customAllocator_.construct(dest++, std::move(*ele++));
    }

    free();

    ptrToFirstFree_ = dest;
    element_ = newData;
    cap_ = element_ + newCapacity;
}

std::pair<std::string*, std::string*> StrVector::allocateAndCopy(const std::string *b, const std::string *e)
{
    std::cout << "allocateAndCopy: " << std::endl;
    auto data = customAllocator_.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVector::push_back(const std::string& str)
{
    std::cout << "Pushing element ..." << str << std::endl;
    checkAndAllocate();
    customAllocator_.construct(ptrToFirstFree_++, str);
}

//copy-constructor
StrVector::StrVector(const StrVector& vect)
{
    std::cout << "copy-constructor.... "<< std::endl;
    auto newSpace = allocateAndCopy(vect.begin(), vect.end());
    element_ = newSpace.first;
    ptrToFirstFree_ = newSpace.second;
    cap_ = newSpace.second;
}

//copy-assignment operator
StrVector &StrVector::operator=(const StrVector &rhs)
{
    std::cout << "copy-assignment.... "<< std::endl;
    auto newSpace = allocateAndCopy(rhs.begin(), rhs.end());
    free();

    element_ =  newSpace.first;
    ptrToFirstFree_ = newSpace.second;
    cap_ = newSpace.second;
    return *this;
}

//destructor
StrVector::~StrVector()
{
    std::cout << "destructor.... "<< std::endl;
    free();
}

int main()
{
    StrVector strVect;
    std::string str = "Hello";
    strVect.push_back(str);
    strVect.push_back("C++");
    strVect.push_back("Java");
    strVect.push_back("Python");
    strVect.push_back("C");

    StrVector strVect_1;
    StrVector strVect_2 = strVect;
    strVect_1 = strVect_2;
    std::cout <<"capacity: " << strVect.size() << std::endl;
    return 0;

}
