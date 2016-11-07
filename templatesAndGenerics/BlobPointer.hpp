#include <iostream>	
#include <string>	
#include <vector>
#include <memory>
#include "Blob.hpp"

template<typename T> class BlobPointer
{
	public:
		typedef typename std::vector<T>::size_type sizeType;
		BlobPointer();
		BlobPointer(Blob<T>& blob, size_t sz = 0);
		~BlobPointer();

		T& operator*();
		//prefix increment & decrement
		BlobPointer<T>& operator++();
        BlobPointer<T>& operator--(); 

        //postfix increment & decrement
        BlobPointer<T> operator++(int);
        BlobPointer<T> operator--(int);

	private:
		std::shared_ptr<std::vector<T>> check(sizeType, const std::string& warning);
		std::weak_ptr<std::vector<T>> wptr_;
		size_t cur_;
};

template<typename T>
BlobPointer<T>::~BlobPointer()
{

}

template<typename T>
BlobPointer<T>::BlobPointer(): cur_(0)
{

}

template<typename T>
BlobPointer<T>::BlobPointer(Blob<T>& blob, size_t sz) : wptr_(blob.data_), cur_(sz)
{

}

template<typename T>
std::shared_ptr<std::vector<T>> BlobPointer<T>::check(sizeType length, const std::string& warning)
{
	auto ret = wptr_.lock(); //lock will return 'nullptr' if vector does not exits and returs shared_ptr if exists

	try{
		if(!ret)
		{
			throw std::runtime_error("unbound BlobPointer....");
		}

		if(length >= ret->size())
		{
			throw std::out_of_range(warning);
		}

		return ret;
	}
	catch(std::runtime_error &err)
	{
		std::cout << "Error: " << err.what() << std::endl;
	}
	catch(std::out_of_range &err)
	{
		std::cout << "Error: " << err.what() << std::endl;
	}
}

template<typename T> T& BlobPointer<T>::operator*()
{
   auto p = check(cur_, "Empty Blob");
   return (*p)[cur_];
}

//prefix increment
template<typename T> BlobPointer<T>& BlobPointer<T>::operator++()
{
	check(cur_, "Increment at the end not possible....");
	++cur_;
	return *this;
}

//prefix decrement
template<typename T> BlobPointer<T>& BlobPointer<T>::operator--()
{
	--cur_;
	check(cur_, "Decrement is not possible....");
	return *this;
}

//postfix increment
template<typename T> BlobPointer<T> BlobPointer<T>::operator++(int)
{
	//BlobPointer<T> curBlob = *this;
	BlobPointer curBlob = *this;
	++*this; //calls the prefix version of the operator++
	return curBlob;
}

//postfix decrement
template<typename T> BlobPointer<T> BlobPointer<T>::operator--(int)
{
	//BlobPointer<T> curBlob = *this;
	BlobPointer curBlob = *this;
	--*this;  //calls the prefix version of the operator--
	return curBlob;
}