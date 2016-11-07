#include <iostream>
#include <string>
#include <memory>

class StrVector
{
  public:
    StrVector(): element_(nullptr), ptrToFirstFree_(nullptr), cap_(nullptr){};
    StrVector(const StrVector&);
    StrVector& operator=(const StrVector&);
    ~StrVector();

    //returns how many locations are occupied
    std::size_t size() const
    {
        //std::cout <<"ptrToFirstFree_: " << ptrToFirstFree_ << std::endl;
        //std::cout <<"element_: " << element_ << std::endl;
        return (ptrToFirstFree_ - element_);
    }

    //returns the total capacity of allocated memory
    std::size_t capacity() const
    {
        return (cap_ - element_);
    }

    //returns the pointer to the start of the memory allocated
    std::string* begin() const
    {
        return element_;
    }

    //returns the pointer to the end of the memory allocated
    std::string* end() const
    {
        return cap_;
    }
    void push_back(const std::string& str);

  private:
    static std::allocator<std::string> customAllocator_;
    std::string *element_;
    std::string *ptrToFirstFree_;
    std::string *cap_;

    void checkAndAllocate();
    void free();
    void reallocate();
    std::pair<std::string*, std::string*> allocateAndCopy(const std::string* begin, const std::string* end);
};

std::allocator<std::string> StrVector::customAllocator_;
