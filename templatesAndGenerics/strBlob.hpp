#ifndef __STR_BLOB_HPP__
#define __STR_BLOB_HPP__

#include <vector>
#include <memory>
#include <iostream>
#include <string>

class StrBlob 
{
   public:
        typedef std::vector<std::string>::size_type size_type;
   		StrBlob();
   		StrBlob(std::initializer_list<std::string> il);
         
        size_type size() const;
        bool isEmpty() const;

        std::string& front();
        std::string& back();
        void push_back(const std::string& str);
        void pop_back();
        void printElements();

   		~StrBlob();
   private:
   	    std::shared_ptr<std::vector<std::string>> data_;
   	    void check(size_type neededSize, const std::string &msg); 
};

#endif //__STR_BLOB_HPP__