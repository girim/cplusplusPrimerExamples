#ifndef __BLOB_HPP__
#define __BLOB_HPP__

#include <iostream>
#include <vector>
#include <string>
#include <memory>

//Forword declaration of template is needed
template <typename> class BlobPointer;

template <typename T>
class Blob 
{
	public:
		friend class BlobPointer<T>;
		typedef typename std::vector<T>::size_type sizeType;
		Blob();
		Blob(std::initializer_list<T> list);
		~Blob();

		bool isEmpty() const;
		sizeType size() const;
        
        T& front();
        T& back();

        void push_back(const T& );
        void pop_back();
        void printContents();

	private:
		void check(sizeType, const std::string&);
		std::shared_ptr<std::vector<T>> data_;
};

template<typename T>
Blob<T>::~Blob()
{

}

template<typename T>
Blob<T>::Blob() : data_(std::make_shared<std::vector<T>>()) 
{

}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data_(std::make_shared<std::vector<T>>(il))
{

}

template<typename T>
void Blob<T>::check(sizeType length, const std::string& msg)
{
	try{
		if(length >= data_->size())
			throw std::out_of_range(msg);
	}
	catch(std::out_of_range &error)
	{
		std::cout << error.what() << std::endl;
	}
}

template<typename T> 
T& Blob<T>::front()
{
	check(0, "Front on empty container....");
	return data_->front();
}

template<typename T>
T& Blob<T>::back()
{
	check(0, "Back on empty container....");
	return data_->back();
}

template<typename T>
void Blob<T>::push_back(const T& element)
{
	data_->push_back(element);
}

template<typename T>
void Blob<T>::pop_back()
{
	check(0, "Pop on empty container....");
	data_->pop_back();
}

template<typename T>
bool Blob<T>::isEmpty() const
{
	return data_->empty();
}

template<typename T>
typename Blob<T>::sizeType Blob<T>::size() const
{
	return data_->size();
}

template<typename T>
void Blob<T>::printContents()
{
	for(auto element: *data_)
	{
		std::cout << "element is " << element << std::endl;
	}
}

#endif // __BLOB_HPP__